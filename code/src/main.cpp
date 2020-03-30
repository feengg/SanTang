#include "CDlgLoginWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CDlgLoginWindow w;
    w.show();
    return a.exec();
}
