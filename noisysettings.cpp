#include "noisysettings.h"
#include "ui_noisysettings.h"

NoisySettings::NoisySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoisySettings)
{
    ui->setupUi(this);

    installEventFilter(this);
}

NoisySettings::~NoisySettings()
{
    delete ui;
}

bool NoisySettings::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        setWindowOpacity(1.0);
        emit enter();
        return true;
    } else if (event->type() == QEvent::Leave) {
        setWindowOpacity(0.2);
        emit leave();
        return true;
    } else {
        return false;
    }
}
