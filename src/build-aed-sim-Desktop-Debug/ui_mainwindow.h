/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *powerButton;
    QFrame *frame;
    QRadioButton *isOk;
    QRadioButton *callForHelp;
    QTextBrowser *mainDisplay;
    QTimeEdit *time;
    QRadioButton *openMouth;
    QRadioButton *checkBreathing;
    QRadioButton *connectDevice;
    QRadioButton *stepBack;
    QRadioButton *analyze;
    QRadioButton *startCPR;
    QTextBrowser *statusDisplay;
    QLabel *statusLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(898, 614);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(750, 500, 141, 61));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 0, 881, 471));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        isOk = new QRadioButton(frame);
        isOk->setObjectName(QString::fromUtf8("isOk"));
        isOk->setGeometry(QRect(160, 220, 16, 21));
        isOk->setAutoFillBackground(false);
        isOk->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        callForHelp = new QRadioButton(frame);
        callForHelp->setObjectName(QString::fromUtf8("callForHelp"));
        callForHelp->setGeometry(QRect(310, 50, 16, 21));
        callForHelp->setAutoFillBackground(false);
        callForHelp->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        mainDisplay = new QTextBrowser(frame);
        mainDisplay->setObjectName(QString::fromUtf8("mainDisplay"));
        mainDisplay->setGeometry(QRect(250, 140, 371, 201));
        time = new QTimeEdit(frame);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(500, 110, 118, 26));
        time->setReadOnly(true);
        openMouth = new QRadioButton(frame);
        openMouth->setObjectName(QString::fromUtf8("openMouth"));
        openMouth->setGeometry(QRect(540, 50, 16, 21));
        openMouth->setAutoFillBackground(false);
        openMouth->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        checkBreathing = new QRadioButton(frame);
        checkBreathing->setObjectName(QString::fromUtf8("checkBreathing"));
        checkBreathing->setGeometry(QRect(700, 160, 16, 21));
        checkBreathing->setAutoFillBackground(false);
        checkBreathing->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        connectDevice = new QRadioButton(frame);
        connectDevice->setObjectName(QString::fromUtf8("connectDevice"));
        connectDevice->setGeometry(QRect(700, 300, 16, 21));
        connectDevice->setAutoFillBackground(false);
        connectDevice->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        stepBack = new QRadioButton(frame);
        stepBack->setObjectName(QString::fromUtf8("stepBack"));
        stepBack->setGeometry(QRect(580, 430, 16, 21));
        stepBack->setAutoFillBackground(false);
        stepBack->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        analyze = new QRadioButton(frame);
        analyze->setObjectName(QString::fromUtf8("analyze"));
        analyze->setGeometry(QRect(430, 370, 16, 21));
        analyze->setAutoFillBackground(false);
        analyze->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        startCPR = new QRadioButton(frame);
        startCPR->setObjectName(QString::fromUtf8("startCPR"));
        startCPR->setGeometry(QRect(280, 430, 16, 21));
        startCPR->setAutoFillBackground(false);
        startCPR->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        statusDisplay = new QTextBrowser(centralwidget);
        statusDisplay->setObjectName(QString::fromUtf8("statusDisplay"));
        statusDisplay->setGeometry(QRect(10, 510, 121, 51));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(40, 490, 61, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        statusLabel->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 898, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        powerButton->setText(QCoreApplication::translate("MainWindow", "ON/OFF", nullptr));
        isOk->setText(QString());
        callForHelp->setText(QString());
        openMouth->setText(QString());
        checkBreathing->setText(QString());
        connectDevice->setText(QString());
        stepBack->setText(QString());
        analyze->setText(QString());
        startCPR->setText(QString());
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
