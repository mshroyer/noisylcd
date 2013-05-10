#ifndef NOISYSETTINGS_H
#define NOISYSETTINGS_H

#include <QDialog>

namespace Ui {
class NoisySettings;
}

class NoisySettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit NoisySettings(QWidget *parent = 0);
    ~NoisySettings();
    
private:
    Ui::NoisySettings *ui;
};

#endif // NOISYSETTINGS_H
