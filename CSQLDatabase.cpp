#include "CSQLDatabase.h"

#include <QVariant>
#include <QDebug>
#include <QMutex>
#pragma execution_character_set("utf-8")
QMutex mutex;
CSQLDatabase::CSQLDatabase()
{
}

CSQLDatabase::~CSQLDatabase()
{
    mSqlDB.close();
    delete mCustomerQuery;
}

bool CSQLDatabase::mbCreateDatabase(const QString& sConnectName, const QString& sDatabaseName, \
    const QString& sHostName, const QString& sUserName, const QString& sPassWord)
{
    mutex.lock();

    msConnectName = sConnectName;
    msHostName = sHostName;
    msDatabaseName = sDatabaseName;
    msUserName = sUserName;
    msPassWord = sPassWord;

    if (QSqlDatabase::contains(sConnectName)) {

        mSqlDB = QSqlDatabase::database(sConnectName);
    }
    else {
        mSqlDB = QSqlDatabase::addDatabase("QSQLITE", sConnectName);
    }

    mSqlDB.setHostName(sHostName);          //设置数据库主机名
    mSqlDB.setDatabaseName(sDatabaseName);  //设置数据库名
    mSqlDB.setUserName(sUserName);          //设置数据库用户名
    mSqlDB.setPassword(sPassWord);          //设置数据库密码
    mSqlDB.open();

    mvInitialTab();

    mutex.unlock();
    return true;
}

//******************************************************************************
// Function			: CSQLDatabase::mbOpenDatabase
// Description		: 打开数据库
// Access			: public 
// Input			: 
// Output			: 
// Return			: bool
// 
// History			:
// 1 Data			: 2020-04-19
// Author			: SanTang  Jiaofeng
//******************************************************************************
bool CSQLDatabase::mbOpenDatabase(const QString& sConnectName, const QString& sDatabaseName, \
    const QString& sHostName, const QString& sUserName, const QString& sPassword)
{
    if (QSqlDatabase::contains(sConnectName)) {

        mSqlDB = QSqlDatabase::database(sConnectName);
    }
    else {
        mSqlDB = QSqlDatabase::addDatabase("QSQLITE", sConnectName);
    }
    mSqlDB.setDatabaseName(sDatabaseName);
    mSqlDB.setHostName(sHostName);
    mSqlDB.setUserName(sUserName);
    mSqlDB.setDatabaseName(sPassword);

    if (mSqlDB.open()) {
        mCustomerQuery = new QSqlQuery(QSqlDatabase::database(msConnectName));
        if (mCustomerQuery) {
            mbCusmerQeryIsOk = true;
        }
        
        mbOrderQueryIsOk = true;
        mbItemQueryIsOk = true;

        mbSupplierQueryIsOk = true;
        mbSupOrdersQueryIsOk = true;
        mbSupItemsQueryIsOk = true;

        mbEmpolyeeQueryIsOk = true;
        mbDepartmentQueryIsOk = true;

        mbMaterialQueryIsOk = true;
        mbProductQuerysIsOk = true;
        mbProjectQueryIsOk = true;
        mbUnitQueryIsOk = true;
        return true;
    }
    msError = mSqlDB.lastError().text();
    return false;
}

QString CSQLDatabase::msGetError()
{
    return msError;
}

void CSQLDatabase::mvInitialTab()
{
    mvCreateCusmerTab();
    mvCrateCusmerOrdTab();
    mvCreateSupplierTable();
}



//******************************************************************************
// Function			: CSQLDatabase::mvCreateCusmerTab
// Description		: 创建客户TABLE
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-04-25
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CSQLDatabase::mvCreateCusmerTab()
{
    int count = 0;

    mCustomerQuery = new QSqlQuery(QSqlDatabase::database(msConnectName));
    bool ret = mCustomerQuery->exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg(CUSMER_TABLE));    //关键的判断
    if (ret) {
        while (mCustomerQuery->next()) {
            count = mCustomerQuery->value(0).toString().toInt();
        }
    }
    if (0 == count) {
        QString str_cmd = "create table %1(";
        str_cmd += "id varchar primary key,";
        str_cmd += "companyname varchar,";
        str_cmd += "name varchar,";
        str_cmd += "tel varchar,";
        str_cmd += "wechat varchar,";
        str_cmd += "qq varchar,";
        str_cmd += "address varchar,";
        str_cmd += "remarks varchar)";
        QString exec_cmd = str_cmd.arg(CUSMER_TABLE);
        mbCusmerQeryIsOk = mCustomerQuery->exec(exec_cmd);
        msError = mCustomerQuery->lastError().text();
    }
    else {
        mbCusmerQeryIsOk = true;
    }
}

//******************************************************************************
// Function			: CSQLDatabase::mbInstCusmerInfo
// Description		: 插入客户信息
// Access			: public 
// Input			: 
// Output			: 
// Return			: bool
// 
// History			:
// 1 Data			: 2020-04-25
// Author			: SanTang  Jiaofeng
//******************************************************************************
bool CSQLDatabase::mbInstCusmerInfo(const SCustomer& customerInfo)
{
    bool ret = false;

    if (!mbCusmerQeryIsOk) {
        msError = "mbCusmerQeryIsOk is false";
        return ret;
    }
    
    // 要插入的客户数据已经存在
    if (mbCusmerInfoIsEx(customerInfo.id, id)) { 
        msError = "data is exist, please update!";
        ret = false;
    }
    else {
        // 插入数据
        mCustomerQuery->prepare(QString("insert into %1 values(?,?,?,?,?,?,?,?)").arg(CUSMER_TABLE));

        mCustomerQuery->bindValue(0, customerInfo.id);
        mCustomerQuery->bindValue(1, customerInfo.companyname);
        mCustomerQuery->bindValue(2, customerInfo.contact);
        mCustomerQuery->bindValue(3, customerInfo.tel);
        mCustomerQuery->bindValue(4, customerInfo.wechat);
        mCustomerQuery->bindValue(5, customerInfo.qq);
        mCustomerQuery->bindValue(6, customerInfo.address);
        mCustomerQuery->bindValue(7, customerInfo.remarks);

        // 执行插入操作
        ret = mCustomerQuery->exec();
        if (!ret) {
            msError = "插入数据失败：" + mCustomerQuery->lastError().text();
        }
        else {
            qDebug() << "插入数据成功！";
            msError = "success!";
        }
    }
    return ret;
}

bool CSQLDatabase::mbUpdataCumerInfo(const SCustomer& customerInfo)
{
    bool ret = false;

    if (!mbCusmerQeryIsOk) {
        return ret;
    }

    // 要插入的数据已经存在
    if (mbCusmerInfoIsEx(customerInfo.id, id))
    {
        QString cmd = QString("update %1 set "
            "level = :level,"
            "where name = :name").arg(CUSMER_TABLE);
        mCustomerQuery->prepare(cmd);

        QString str_cmd = "create table %1(";
        str_cmd += "id varchar primary key,";
        str_cmd += "companyname varchar,";
        str_cmd += "contact varchar,";
        str_cmd += "tel varchar,";
        str_cmd += "wechat varchar,";
        str_cmd += "qq varchar,";
        str_cmd += "address varchar,";
        str_cmd += "remarks varchar)";

        QString s_cmd = "update %1 set id = :id,";
        s_cmd += "companyname = :companyname,";
        s_cmd += "contact = :contact,";
        s_cmd += "tel = :tel,";

        mCustomerQuery->bindValue(":id", customerInfo.id);
        mCustomerQuery->bindValue(":companyname", customerInfo.companyname);
        mCustomerQuery->bindValue(":contact", customerInfo.contact);
        mCustomerQuery->bindValue(":tel", customerInfo.tel);
        mCustomerQuery->bindValue(":wechat", customerInfo.wechat);
        mCustomerQuery->bindValue(":qq", customerInfo.qq);
        mCustomerQuery->bindValue(":address", customerInfo.address);
        mCustomerQuery->bindValue(":remarks", customerInfo.remarks);
        ret = mCustomerQuery->exec();
        if (!ret) {
            msError = "更新数据失败：" + mCustomerQuery->lastError().text();
        }
    } else
    {
        msError = "data is not exist!";
        ret = false;
    }
    return ret;
}

//******************************************************************************
// Function			: CSQLDatabase::mbGetLstCusmerInfo
// Description		: 获取客户列表
// Access			: public 
// Input			: 
// Output			: 
// Return			: bool
// 
// History			:
// 1 Data			: 2020-04-25
// Author			: SanTang  Jiaofeng
//******************************************************************************
bool CSQLDatabase::mbGetLstCusmerInfo(const QString& sType, const QString& sKey, QList<SCustomer>& customerInfoList)
{
    bool ret = false;

    if (!mbCusmerQeryIsOk) {
        return ret;
    }
    QString s_cmd = "select * from %1 where " + sType + " like '%%2%'";
    ret = mCustomerQuery->exec(s_cmd.arg(CUSMER_TABLE).arg(name));
    msError = mCustomerQuery->lastError().text();

    if (true == ret) {
        mvGetLstCusmerInfo(mCustomerQuery, customerInfoList);
        if (customerInfoList.isEmpty())
        {
            ret = false;
        }
    }
    return ret;
}

//******************************************************************************
// Function			: CSQLDatabase::mbGetLstCusmerInfo
// Description		: 获取客户列表
// Access			: public 
// Input			: 
// Output			: 
// Return			: bool
// 
// History			:
// 1 Data			: 2020-04-25
// Author			: SanTang  Jiaofeng
//******************************************************************************
bool CSQLDatabase::mbGetLstCusmerInfo(QList<SCustomer>& LstCusmerInfo)
{
    bool ret = false;

    if (!mbCusmerQeryIsOk) {
        return ret;
    }
    QString s_cmd = "select * from %1 ";
    ret = mCustomerQuery->exec(s_cmd.arg(CUSMER_TABLE));
    msError = mCustomerQuery->lastError().text();

    LstCusmerInfo.clear();

    if (true == ret) {
        mvGetLstCusmerInfo(mCustomerQuery, LstCusmerInfo);
        if (LstCusmerInfo.isEmpty()) {
            ret = false;
        }
    }
    return ret;
}

void CSQLDatabase::mvGetLstCusmerInfo(QSqlQuery* query, QList<SCustomer>& customerInfoList)
{
    while (query->next()) {
        SCustomer info;
        info.id = query->value(0).toString();
        info.companyname = query->value(1).toString();
        info.contact = query->value(2).toString();
        info.tel = query->value(3).toString();
        info.wechat = query->value(4).toString();
        info.qq = query->value(5).toString();
        info.address = query->value(6).toString();
        info.remarks = query->value(7).toString();
        customerInfoList.append(info);
    }
}

// 判断客户信息是否存在
bool CSQLDatabase::mbCusmerInfoIsEx(const QString& sKey, const QString& sType)
{
    int count = 0;
    if (mbCusmerQeryIsOk) {
        QString exec_cmd = "select count(*) from %1 where " + sType + "='%2'";
        mCustomerQuery->exec(exec_cmd.arg(CUSMER_TABLE).arg(sKey));
        while (mCustomerQuery->next()) {
            count = mCustomerQuery->value(0).toString().toInt();
        }
    }
    return (0 != count) ? true : false;
}

bool CSQLDatabase::mbDelCusmerInfo(const QString& sName)
{
    bool ret = false;

    if (mbCusmerQeryIsOk) {
        mCustomerQuery->prepare(QString("delete from %1 where name = ?").arg(CUSMER_TABLE));
        mCustomerQuery->addBindValue(sName);
        ret = mCustomerQuery->exec();
        if (!ret) {
            msError = mCustomerQuery->lastError().text();
        }
        else {
            msError = "删除客户信息成功！";
        }
    }

    return ret;
}

void CSQLDatabase::mvCrateCusmerOrdTab()
{
    mOrderQuery = new QSqlQuery(QSqlDatabase::database(msConnectName));

    QString str_cmd = "create table %1(";
    str_cmd += "id varchar primary key,";       // 订单编号
    str_cmd += "customerid varchar,";           // 客户ID
    str_cmd += "designerid varchar,";           // 设计员ID
    str_cmd += "clerkid varchar,";              // 业务员ID
    str_cmd += "deliveryway varchar,";          // 送货方式
    str_cmd += "orderstatus varchar,";          // 订单状态
    str_cmd += "prepay varchar,";               // 定金
    str_cmd += "totalprice varchar,";           // 总价
    str_cmd += "deliveryprice varchar,";        // 运费
    str_cmd += "orderdate varchar,";            // 下单时间
    str_cmd += "deliverydate varchar,";         // 交货时间
    str_cmd += "remark varchar)";               // 备注
    QString exec_cmd = str_cmd.arg(CUSMER_ORDER_TABLE);
    mbOrderQueryIsOk = mOrderQuery->exec(exec_cmd);
    msError = mOrderQuery->lastError().text();
}

void CSQLDatabase::mvCreateCusmerOrdItemTab()
{
    int count = 0;
    mbItemQueryIsOk = false;

    mItemQuery = new QSqlQuery(QSqlDatabase::database(msConnectName));

    QString exec_str = "select count(*) from sqlite_master where type='table' and name='%1'";

    //关键的判断
    bool ret = mItemQuery->exec(exec_str.arg(CUSMER_ORDER_TABLE));
    if (ret) {
        while (mItemQuery->next()) {
            count = mItemQuery->value(0).toString().toInt();
        }
    }
    if (0 == count) {
        QString str_cmd = "create table %1(";
        str_cmd += "id varchar primary key,";       // 订单明细编号
        str_cmd += "orderid varchar,";              // 订单ID
        str_cmd += "materialid varchar,";           // 耗材ID
        str_cmd += "projectid varchar,";            // 项目ID
        str_cmd += "num varchar,";                  // 数量
        str_cmd += "width varchar,";                // 宽度
        str_cmd += "height varchar,";               // 高度
        str_cmd += "area varchar,";                 // 面积
        str_cmd += "unitprice varchar,";            // 单价
        str_cmd += "price varchar,";                // 金额
        str_cmd += "content varchar,";              // 制作内容
        str_cmd += "remark varchar)";               // 备注
        QString exec_cmd = str_cmd.arg(CUSMER_TABLE);
        mbCusmerQeryIsOk = mItemQuery->exec(exec_cmd);
        msError = mItemQuery->lastError().text();
    }
    else {
        mbItemQueryIsOk = true;
    }
}

void CSQLDatabase::mvCreateSupplierTable()
{
    mSupplierQuery = new QSqlQuery(QSqlDatabase::database(msConnectName));

    QString str_cmd = "create table %1(";
    str_cmd += "id varchar primary key,";       // 供应商ID
    str_cmd += "companyname varchar,";          // 供应商公司名称
    str_cmd += "contacter varchar,";            // 联系人
    str_cmd += "tel varchar,";                  // 供货商电话
    str_cmd += "wechat varchar,";               // 微信帐号
    str_cmd += "qq varchar,";                   // QQ帐号
    str_cmd += "address varchar,";              // 供货商地址
    str_cmd += "remark varchar)";               // 备注
    QString exec_cmd = str_cmd.arg(SUPPLY_TABLE);
    mbSupplierQueryIsOk = mSupplierQuery->exec(exec_cmd);
    msError = mSupplierQuery->lastError().text();
}

void CSQLDatabase::mvbCreateSupOrderTable()
{

}

void CSQLDatabase::mvCreateSupItemTable()
{

}

void CSQLDatabase::mvCreateDepartTable()
{

}

void CSQLDatabase::mvCreateEmpolyeeTable()
{

}

void CSQLDatabase::mvCreateMaterialTable()
{

}

void CSQLDatabase::mvCreateProductTable()
{

}

void CSQLDatabase::mvCreateProjectTable()
{

}

void CSQLDatabase::mvCreateUnitTable()
{

}


