#ifndef TONESPINBOX_H
#define TONESPINBOX_H

#include <QDoubleSpinBox>

class ToneSpinBox : public QDoubleSpinBox
{
    Q_OBJECT

public:
    explicit ToneSpinBox(QWidget *parent = 0);
    virtual void stepBy(int step);

private slots:
    void editingFinished();

signals:
    void stepUp();
    void stepDown();
    void editingFinishedWithValue(double);
};

#endif // TONESPINBOX_H
