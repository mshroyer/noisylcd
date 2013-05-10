#ifndef NOISYLCD_H
#define NOISYLCD_H

#include <QMainWindow>
#include "noisysettings.h"

namespace Ui {
class NoisyLCD;
}

class NoisyLCD : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit NoisyLCD(QWidget *parent = 0);
    ~NoisyLCD();

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    Ui::NoisyLCD *ui;
    NoisySettings *settings;

signals:
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // NOISYLCD_H
