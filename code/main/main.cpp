#include "../include/CDlgSanTang.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CDlgSanTang w;
    w.show();
    return a.exec();
}
