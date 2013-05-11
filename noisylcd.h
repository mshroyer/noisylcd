#ifndef NOISYLCD_H
#define NOISYLCD_H

#include <QMainWindow>
#include "noisysettings.h"

class NoisyLCD : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit NoisyLCD(QWidget *parent = 0);
    ~NoisyLCD();

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    NoisySettings *settings;

signals:
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // NOISYLCD_H
