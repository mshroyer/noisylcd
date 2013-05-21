#ifndef NOISYLCD_H
#define NOISYLCD_H

#include <QMainWindow>
#include <QGraphicsView>
#include "noisysettings.h"

class NoisyLCD : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit NoisyLCD(QWidget *parent = 0);
    ~NoisyLCD();
    double tone();

protected:
    bool eventFilter(QObject *object, QEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    NoisySettings *settings;
    QGraphicsView *gv;
    // Monitor's refresh rate in Hz
    double refresh;
    // Pixel height of one black/white bar pair
    unsigned int lines;
    void redraw();

signals:
    void mouseReleaseEvent(QMouseEvent *);
    void toneChanged(double);

public slots:
    void setRefresh(double newRefresh);
    void setTone(double newTone);
    void incTone();
    void decTone();
};

#endif // NOISYLCD_H
