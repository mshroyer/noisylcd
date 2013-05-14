#include "noisylcd.h"
#include "ui_noisylcd.h"
#include "noisysettings.h"
#include "ui_noisysettings.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

NoisyLCD::NoisyLCD(QWidget *parent) : QMainWindow(parent)
{
    settings = new NoisySettings(this);

    installEventFilter(this);
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
    double duty = 0.5;
    unsigned int lineHeight = height() * settings->ui->refresh->value() / (1000 * settings->ui->tone->value());
    unsigned int blackHeight = duty * lineHeight;
    unsigned int i;

    qDebug() << "lineHeight =" << lineHeight;
    qDebug() << "blackHeight =" << blackHeight;

    QPainter p;
    p.begin(this);
    for (i=0; i<height(); i++) {
        if (i%lineHeight <= blackHeight)
            p.setPen(Qt::black);
        else
            p.setPen(Qt::white);

        p.drawRect(0, i, width(), i);
    }
    p.end();
}

void NoisyLCD::updatePattern(int lines, double dutyCycle)
{
}
