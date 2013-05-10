#include "noisysettings.h"
#include "ui_noisysettings.h"

NoisySettings::NoisySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoisySettings)
{
    ui->setupUi(this);
}

NoisySettings::~NoisySettings()
{
    delete ui;
}
