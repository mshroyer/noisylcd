#include "noisylcd.h"
#include "ui_noisylcd.h"
#include "noisysettings.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

NoisyLCD::NoisyLCD(QWidget *parent) : QMainWindow(parent)
{
    settings = new NoisySettings(this);

    gv = new QGraphicsView(this);
    setCentralWidget(gv);
    //gv->viewport()->setFocusProxy(0);
    gv->viewport()->installEventFilter(this);

    showFullScreen();

    connect(this, SIGNAL(mouseReleaseEvent(QMouseEvent*)), settings, SLOT(show()));
}

NoisyLCD::~NoisyLCD()
{
}

bool NoisyLCD::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease) {
        emit mouseReleaseEvent((QMouseEvent*)event);
        return true;
    } else {
        return false;
    }
}

void NoisyLCD::paintEvent(QPaintEvent *event)
{
    event->accept();

    QPainter painter(gv->viewport());
    //painter.begin();
    painter.setPen(Qt::blue);
    painter.drawRect(x(), y(), 10, 10);
    //painter.end();
}

void NoisyLCD::updatePattern(int lines, double dutyCycle)
{
}
