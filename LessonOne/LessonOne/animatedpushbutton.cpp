#include "animatedpushbutton.h"

AnimatedPushButton::AnimatedPushButton(QWidget* parent) :
    QPushButton(parent)
{
    QFont font;
    font.setPointSize(14);

    this->setFixedSize(200, 40);
    this->setText("Log in");
    this->setFont(font);
    this->setStyleSheet("QPushButton:hover { background: #d6d6d6}"
                        "QPushButton:!hover { background: #f6f6f6 }"
                        "QPushButton:pressed { background: #bbbbbb }");
}
