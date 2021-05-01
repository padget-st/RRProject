#include <QtCore/QCoreApplication>
#include "ScreenStack.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ScreenStack ss;
    ss.show();
    //Lamp lamp;
    //lamp.id = 1;
    //lamp.name = "LBO-1";
    //lamp.type = "inner";
    //lamp.power = 5;
    //LampWidget* lw = new LampWidget(lamp);
    //lw->show();

    return app.exec();
}
