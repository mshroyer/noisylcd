#include <QRect>

#include "noisysettings.h"
#include "ui_noisysettings.h"

const double opacityFull = 1.0;
const double opacityPartial = 0.4;

NoisySettings::NoisySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoisySettings)
{
    ui->setupUi(this);

    installEventFilter(this);
    setWindowOpacity(0.0);

    connect(ui->refresh, SIGNAL(valueChanged(double)), this, SLOT(settingsChanged()));
    connect(ui->tone, SIGNAL(valueChanged(double)), this, SLOT(settingsChanged()));
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

    // Position the dialog window in the lowe-right corner of the screen the
    // first time it is displayed.
    QRect frameRect = this->frameGeometry();
    int xOffset = parentWidget()->width() - frameRect.width() - margin;
    int yOffset = parentWidget()->height() - frameRect.height() - margin;
    move(xOffset, yOffset);
    setWindowOpacity(opacityPartial);
    hasBeenShown = true;
}

void NoisySettings::settingsChanged()
{
    parentWidget()->update();
    qApp->processEvents();
}
