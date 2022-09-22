#ifndef ANIMATEDPUSHBUTTON_H
#define ANIMATEDPUSHBUTTON_H

#include <QPushButton>


class AnimatedPushButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QColor color WRITE setColor)
    Q_PROPERTY(int opacity WRITE setOpacity)

public:
    explicit AnimatedPushButton(QWidget* paarent = nullptr);

    void setColor(QColor color) { setStyleSheet(QString("background: " + color.name())); }

    void setOpacity(int opacity) { setStyleSheet(QString("lineedit-opacity: " + QString::number(opacity) + "; border: #fcfcff;")); }
};

#endif // ANIMATEDPUSHBUTTON_H
