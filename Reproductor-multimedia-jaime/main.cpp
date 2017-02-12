#include "repmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RepMainWindow w;
    w.show();

    return a.exec();
}
