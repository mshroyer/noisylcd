#include <QtGui/QApplication>
#include "noisylcd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NoisyLCD w;
    w.show();
    
    return a.exec();
}
