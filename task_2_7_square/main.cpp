#include <QApplication>
#include "win.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Win window;
    window.show();

    return app.exec();
}