#include <QRect>

#include "noisysettings.h"
#include "ui_noisysettings.h"

const double opacityFull = 1.0;
const double opacityPartial = 0.3;

NoisySettings::NoisySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoisySettings)
{
    ui->setupUi(this);

    // We have to show the window before frameGeometry() will return anything meaningful here
    setWindowOpacity(0.0);
    show();
    QRect frameRect = this->frameGeometry();
    int xOffset = parentWidget()->width() - frameRect.width() - 10;
    int yOffset = parentWidget()->height() - frameRect.height() - 10;
    move(xOffset, yOffset);

    installEventFilter(this);
    setWindowOpacity(opacityPartial);
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
