#ifndef ANIMATIONWIDGET_H
#define ANIMATIONWIDGET_H

#include <QWidget>



class AnimationWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color WRITE setColor)
    Q_PROPERTY(int opacity WRITE setOpacity)

public:
    explicit AnimationWidget(QWidget* parent = nullptr);

    void setColor(QColor color) { setStyleSheet(QString("background: " + color.name())); }

    void setOpacity(int opacity) { setStyleSheet(QString("lineedit-opacity: " + QString::number(opacity))); }

protected:
    void paintEvent(QPaintEvent*);
};

#endif // ANIMATIONWIDGET_H
