#include "animationwidget.h"

#include <QPainter>
#include <QStyleOption>

AnimationWidget::AnimationWidget(QWidget* parent) :
    QWidget(parent)
{
    this->setFixedSize(300, 250);
    this->setStyleSheet("background: white; border-radius: 5px");
}

void AnimationWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
