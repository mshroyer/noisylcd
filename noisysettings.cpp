#include <QRect>
#include <QDebug>
#include "noisylcd.h"
#include "noisysettings.h"
#include "ui_noisysettings.h"

const double opacityFull = 1.0;
const double opacityPartial = 0.4;

NoisySettings::NoisySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoisySettings)
{
    ui->setupUi(this);
    hasBeenShown = false;

    installEventFilter(this);
    setWindowOpacity(0.0);

    connect(ui->refresh, SIGNAL(valueChanged(double)), parent, SLOT(setRefresh(double)));
    connect(ui->tone, SIGNAL(editingFinishedWithValue(double)), parent, SLOT(setTone(double)));
    connect(ui->tone, SIGNAL(stepUp()), parent, SLOT(incTone()));
    connect(ui->tone, SIGNAL(stepDown()), parent, SLOT(decTone()));
    connect(parent, SIGNAL(toneChanged(double)), ui->tone, SLOT(setValue(double)));
}

NoisySettings::~NoisySettings()
{
    delete ui;
}

bool NoisySettings::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        setWindowOpacity(opacityFull);
        emit enter();
        return true;
    } else if (event->type() == QEvent::Leave) {
        setWindowOpacity(opacityPartial);
        emit leave();
        return true;
    } else {
        return false;
    }
}

void NoisySettings::showEvent(QShowEvent *event)
{
    const int margin = 10;

    if (hasBeenShown)
        return;

    // Position the dialog window in the lower-right corner of the screen the
    // first time it is displayed.
    QRect frameRect = this->frameGeometry();
    int xOffset = parentWidget()->x() + parentWidget()->width() - frameRect.width() - margin;
    int yOffset = parentWidget()->y() + parentWidget()->height() - frameRect.height() - margin;
    move(xOffset, yOffset);
    setWindowOpacity(opacityPartial);
    hasBeenShown = true;
}
