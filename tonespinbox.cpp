#include "tonespinbox.h"

ToneSpinBox::ToneSpinBox(QWidget *parent) :
    QDoubleSpinBox(parent)
{
    connect(this, SIGNAL(editingFinished()), this, SLOT(editingFinished()));
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

void ToneSpinBox::editingFinished()
{
    emit editingFinishedWithValue(value());
}
