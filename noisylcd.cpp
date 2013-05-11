#include <QDebug>

#include "noisylcd.h"
#include "ui_noisylcd.h"
#include "noisysettings.h"

NoisyLCD::NoisyLCD(QWidget *parent) : QMainWindow(parent)
{
    settings = new NoisySettings(this);

    installEventFilter(this);
    connect(this, SIGNAL(mouseReleaseEvent(QMouseEvent*)), settings, SLOT(show()));
}

NoisyLCD::~NoisyLCD()
{
}

bool NoisyLCD::eventFilter(QObject *object, QEvent *event)
{
    if (object == this && event->type() == QEvent::MouseButtonRelease) {
        emit mouseReleaseEvent((QMouseEvent*)event);
        return true;
    } else {
        return false;
    }
}
