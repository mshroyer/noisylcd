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

protected:
    bool eventFilter(QObject *object, QEvent *event);
    void showEvent(QShowEvent *event);

private:
    Ui::NoisySettings *ui;
    bool hasBeenShown;

signals:
    void enter();
    void leave();

private slots:
    void toneEditingFinished();
};

#endif // NOISYSETTINGS_H
