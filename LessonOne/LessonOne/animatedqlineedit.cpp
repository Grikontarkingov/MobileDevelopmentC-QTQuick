#include "animatedqlineedit.h"

AnimatedQLineEdit::AnimatedQLineEdit(QWidget* parent) :
    QLineEdit(parent)
{
    QFont font;
    font.setPointSize(14);

    this->setFixedSize(200, 40);
    this->setAlignment(Qt::AlignCenter);
    this->setFont(font);
    this->setStyleSheet("background: #535353");
}
