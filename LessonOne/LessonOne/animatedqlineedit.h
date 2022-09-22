#ifndef ANIMATEDQLABEL_H
#define ANIMATEDQLABEL_H

#include <QLineEdit>


class AnimatedQLineEdit : public QLineEdit
{
    Q_OBJECT
    Q_PROPERTY(QColor color WRITE setColor)
    Q_PROPERTY(int opacity WRITE setOpacity)

public:
    explicit AnimatedQLineEdit(QWidget* paarent = nullptr);

    void setColor(QColor color) { setStyleSheet(QString("background: " + color.name())); }

    void setOpacity(int opacity) { setStyleSheet(QString("opacity: " + QString::number(opacity) + "; border: #fcfcff;")); }
};

#endif // ANIMATEDQLABEL_H
