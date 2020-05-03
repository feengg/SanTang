#include "CCustomer.h"

CCustomer::CCustomer()
{

}

CCustomer::CCustomer(const QString& sName, const QString& sTelNum, const QString& sAddress)
    : msName(sName)
    , msTelNum(sTelNum)
    , msAddress(sAddress)
{

}

CCustomer::~CCustomer()
{

}
