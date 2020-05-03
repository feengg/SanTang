
#include <QApplication>
#include <QTextCodec>
#include <memory>
#include "Global.h"
#include "SanTang.h"
#include "loginwindow.h"
#include "CDlgBillMan.h"
#include "CDlgAddItem.h"
#include "CDlgNewBill.h"
#include "CDlgOrderToolBar.h"
#include "CDlgOrderManToolBar.h"
#include "CDlgOrderMan.h"
#include "CSQLDatabase.h"
#include "CDlgCusmerEdit.h"


int main(int argc, char *argv[])
{
    QApplication exe(argc, argv);
    if (!mSqlDB->mbCreateDatabase("A", "B.db", "C", "D", "E")) {
        return 0;
    }

    SCustomer scumer;
    scumer.id = "100";
    scumer.companyname = "123";
    scumer.contact = "121";
    scumer.tel = "12345678901";
    scumer.wechat = "001";
    scumer.address = "菏泽";

    mSqlDB->mbInstCusmerInfo(scumer);

    QList<SCustomer> lst_cusmers;
    mSqlDB->mbGetLstCusmerInfo(lst_cusmers);


    return exe.exec();

}
