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
    friend class NoisyLCD;

protected:
    bool eventFilter(QObject *object, QEvent *event);
    void showEvent(QShowEvent *event);

private:
    Ui::NoisySettings *ui;
    bool hasBeenShown = false;

signals:
    void enter();
    void leave();

protected slots:
    void settingsChanged();
};

#endif // NOISYSETTINGS_H
