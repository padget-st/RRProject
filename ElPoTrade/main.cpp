#include <QtCore/QCoreApplication>
#include "ScreenStack.h"
#include "fstream"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ScreenStack ss;
    ss.show();

    return app.exec();
}
