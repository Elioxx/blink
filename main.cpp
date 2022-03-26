#include "blink.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    blink w;
    w.show();

    return a.exec();
}
