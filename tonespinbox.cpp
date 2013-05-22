#include "tonespinbox.h"

ToneSpinBox::ToneSpinBox(QWidget *parent) :
    QDoubleSpinBox(parent)
{
}

void ToneSpinBox::stepBy(int step)
{
    for (; step > 0; step--) {
        emit stepDown();
    }
    for (; step < 0; step++) {
        emit stepUp();
    }
}
