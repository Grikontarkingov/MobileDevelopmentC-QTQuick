#include "mainwindow.h"
#include "animatedqlineedit.h"
#include "animatedpushbutton.h"
#include "animationwidget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(640, 480);
    this->setWindowTitle("Login form");
    this->setStyleSheet("background: #e5ecef");

    authWindow = new AnimationWidget(this);
    authWindow->move(((this->width() / 2) - (authWindow->width() / 2)),
                     (this->height() / 2) - (authWindow->height() / 2));
    authWindow->setFixedSize(300, 250);
    authWindow->setStyleSheet("background: white; border-radius: 5px");

    column = new QVBoxLayout;
    authWindow->setLayout(column);
    column->setSpacing(32);
    column->setAlignment(Qt::AlignCenter);

    loginLineEdit = new AnimatedQLineEdit;
    column->addWidget(loginLineEdit);
    loginLineEdit->setPlaceholderText("login");
    connect(loginLineEdit, &AnimatedQLineEdit::returnPressed, this, &MainWindow::on_checkLoginPassword);

    passwordLineEdit = new AnimatedQLineEdit;
    column->addWidget(passwordLineEdit);
    passwordLineEdit->setPlaceholderText("password");
    passwordLineEdit->setEchoMode(AnimatedQLineEdit::Password);
    connect(passwordLineEdit, &AnimatedQLineEdit::returnPressed, this, &MainWindow::on_checkLoginPassword);

    submitButton = new AnimatedPushButton;
    column->addWidget(submitButton);
    connect(submitButton, &AnimatedPushButton::clicked, this, &MainWindow::on_checkLoginPassword);

    createAnimationChangeColorFail();
    createAnimationShakingAuthWindowFail();
    disappearance();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createAnimationChangeColorFail()
{
    changeColorLoginTextEditFail = new QPropertyAnimation(loginLineEdit, "color");
    changeColorLoginTextEditFail->setDuration(400);
    changeColorLoginTextEditFail->setStartValue(QColor("dark red"));
    changeColorLoginTextEditFail->setEndValue(QColor(authWindowColor));

    changeColorPasswordTextEditFail= new QPropertyAnimation(passwordLineEdit, "color");
    changeColorPasswordTextEditFail->setDuration(400);
    changeColorPasswordTextEditFail->setStartValue(QColor("dark red"));
    changeColorPasswordTextEditFail->setEndValue(QColor(authWindowColor));

    parallelAnimationFail = new QParallelAnimationGroup;
    parallelAnimationFail->addAnimation(changeColorLoginTextEditFail);
    parallelAnimationFail->addAnimation(changeColorPasswordTextEditFail);
}

void MainWindow::createAnimationShakingAuthWindowFail()
{
    shakingAuthWindow = new QPropertyAnimation(authWindow, "pos");
    shakingAuthWindow->setDuration(50);
    shakingAuthWindow->setStartValue(QPoint(authWindow->x() + 5, authWindow->y() + 5));
    shakingAuthWindow->setDuration(100);
    shakingAuthWindow->setKeyValueAt(0.5f, QPoint(authWindow->x() - 10, authWindow->y() - 10));
    shakingAuthWindow->setDuration(50);
    shakingAuthWindow->setEndValue(QPoint(authWindow->x(), authWindow->y()));
    parallelAnimationFail->addAnimation(shakingAuthWindow);
}

void MainWindow::disappearance()
{
    disappearanceLogin = new QPropertyAnimation(loginLineEdit, "opacity");
    disappearanceLogin->setDuration(600);
    disappearanceLogin->setStartValue(1.0);
    disappearanceLogin->setEndValue(0);

    disappearancePassword = new QPropertyAnimation(passwordLineEdit, "opacity");
    disappearancePassword->setDuration(600);
    disappearancePassword->setStartValue(1.0);
    disappearancePassword->setEndValue(0);

    disappearanceButton = new QPropertyAnimation(submitButton, "opacity");
    disappearanceButton->setDuration(600);
    disappearanceButton->setStartValue(1.0);
    disappearanceButton->setEndValue(0);

    disappearanceAuthWindow = new QPropertyAnimation(authWindow, "opacity");
    disappearanceAuthWindow->setDuration(600);
    disappearanceAuthWindow->setStartValue(1.0);
    disappearanceAuthWindow->setEndValue(0);

    disappearanceGroup = new QSequentialAnimationGroup;
    disappearanceGroup->addAnimation(disappearanceLogin);
    disappearanceGroup->addAnimation(disappearancePassword);
    disappearanceGroup->addAnimation(disappearanceButton);
    disappearanceGroup->addAnimation(disappearanceAuthWindow);
}

void MainWindow::on_checkLoginPassword()
{
    if(login == loginLineEdit->text() && password == passwordLineEdit->text())
    {
        loginLineEdit->clear();
        loginLineEdit->setPlaceholderText("");

        passwordLineEdit->clear();
        passwordLineEdit->setPlaceholderText("");

        submitButton->setText("");

        disappearanceGroup->start();

    }
    else
    {
        parallelAnimationFail->start();
    }
}
