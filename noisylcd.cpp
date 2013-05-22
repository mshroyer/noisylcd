#include "noisylcd.h"
#include "noisysettings.h"
#include "ui_noisysettings.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

static inline int round(double d)
{
    return static_cast<int>(d + 0.5);
}

NoisyLCD::NoisyLCD(QWidget *parent) : QMainWindow(parent), refresh(60), lines(20)
{
    settings = new NoisySettings(this);

    installEventFilter(this);
    showFullScreen();

    connect(this, SIGNAL(mouseReleaseEvent(QMouseEvent*)), settings, SLOT(show()));
}

NoisyLCD::~NoisyLCD()
{
}

double NoisyLCD::tone()
{
    return height() * refresh / lines;
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
    const double duty = 0.5;
    const unsigned int blackLines = duty * lines;
    unsigned int i;

    QPainter p;
    p.begin(this);
    for (i=0; i<height(); i++) {
        if (i%lines <= blackLines)
            p.setPen(Qt::black);
        else
            p.setPen(Qt::white);

        p.drawRect(0, i, width(), i);
    }
    p.end();
}

void NoisyLCD::redraw()
{
    update();
    qApp->processEvents();
}

void NoisyLCD::setRefresh(double newRefresh)
{
    refresh = newRefresh;

    // We're not reinterpreting lines here, so changing the refresh rate can
    // result in a new effective tone.
    emit toneChanged(tone());
    redraw();
}

void NoisyLCD::setTone(double newTone)
{
    // Choose a lines value approximating the indicated tone as closely
    // as possible.
    lines = round(height() * refresh / newTone);
    emit toneChanged(tone());
    redraw();
}

void NoisyLCD::incTone()
{
    lines++;
    emit toneChanged(tone());
    redraw();
}

void NoisyLCD::decTone()
{
    if (lines > 2) lines--;
    emit toneChanged(tone());
    redraw();
}
