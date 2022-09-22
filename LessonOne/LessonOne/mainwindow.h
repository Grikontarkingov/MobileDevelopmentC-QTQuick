#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QVBoxLayout;
class QLineEdit;
class QPushButton;
class QPropertyAnimation;
class QParallelAnimationGroup;
class AnimatedQLineEdit;
class QSequentialAnimationGroup;
class AnimatedPushButton;
class AnimationWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createAnimationChangeColorFail();
    void createAnimationShakingAuthWindowFail();
    void disappearance();

    AnimationWidget* authWindow;
    QVBoxLayout* column;
    AnimatedQLineEdit* loginLineEdit;
    AnimatedQLineEdit* passwordLineEdit;
    AnimatedPushButton* submitButton;

    QPropertyAnimation* changeColorLoginTextEditFail;
    QPropertyAnimation* changeColorPasswordTextEditFail;
    QPropertyAnimation* shakingAuthWindow;
    QPropertyAnimation* disappearanceLogin;
    QPropertyAnimation* disappearancePassword;
    QPropertyAnimation* disappearanceButton;
    QPropertyAnimation* disappearanceAuthWindow;
    QSequentialAnimationGroup* disappearanceGroup;
    QParallelAnimationGroup* parallelAnimationFail;

    const QString authWindowColor { "#535353" };
    const QString login { "login" };
    const QString password { "password" };

private slots:
    void on_checkLoginPassword();
};
#endif // MAINWINDOW_H
