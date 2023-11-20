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
#include <QtWidgets/QLineEdit>
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
    QFrame *frame;
    QRadioButton *isOk;
    QRadioButton *callForHelp;
    QTextBrowser *mainDisplay2;
    QTimeEdit *time;
    QRadioButton *connectDevice;
    QRadioButton *stepBack;
    QRadioButton *analyze;
    QRadioButton *startCPR;
    QTextBrowser *mainDisplay;
    QLabel *shockCountLabel;
    QLineEdit *shockCountEdit;
    QLabel *stage1Label;
    QLabel *stage2Label;
    QLabel *stage3Label;
    QLabel *stage4Label;
    QLabel *stage5_1Label;
    QLabel *stage5_2Label;
    QLabel *stage6Label;
    QTextBrowser *statusDisplay;
    QLabel *statusLabel;
    QPushButton *shockButton;
    QPushButton *toggleCprButton;
    QTextBrowser *statusDisplay2;
    QPushButton *applyElectrodeButton;
    QPushButton *powerButton;
    QPushButton *testButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(961, 655);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 0, 941, 511));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        isOk = new QRadioButton(frame);
        isOk->setObjectName(QString::fromUtf8("isOk"));
        isOk->setGeometry(QRect(210, 270, 16, 21));
        isOk->setAutoFillBackground(false);
        isOk->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        callForHelp = new QRadioButton(frame);
        callForHelp->setObjectName(QString::fromUtf8("callForHelp"));
        callForHelp->setGeometry(QRect(470, 120, 16, 21));
        callForHelp->setAutoFillBackground(false);
        callForHelp->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        mainDisplay2 = new QTextBrowser(frame);
        mainDisplay2->setObjectName(QString::fromUtf8("mainDisplay2"));
        mainDisplay2->setGeometry(QRect(290, 240, 361, 91));
        time = new QTimeEdit(frame);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(557, 120, 91, 26));
        time->setReadOnly(true);
        connectDevice = new QRadioButton(frame);
        connectDevice->setObjectName(QString::fromUtf8("connectDevice"));
        connectDevice->setGeometry(QRect(710, 280, 16, 21));
        connectDevice->setAutoFillBackground(false);
        connectDevice->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        stepBack = new QRadioButton(frame);
        stepBack->setObjectName(QString::fromUtf8("stepBack"));
        stepBack->setGeometry(QRect(680, 350, 16, 21));
        stepBack->setAutoFillBackground(false);
        stepBack->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        analyze = new QRadioButton(frame);
        analyze->setObjectName(QString::fromUtf8("analyze"));
        analyze->setGeometry(QRect(470, 430, 16, 21));
        analyze->setAutoFillBackground(false);
        analyze->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        startCPR = new QRadioButton(frame);
        startCPR->setObjectName(QString::fromUtf8("startCPR"));
        startCPR->setGeometry(QRect(250, 440, 16, 21));
        startCPR->setAutoFillBackground(false);
        startCPR->setStyleSheet(QString::fromUtf8("[type='radio'] {\n"
"height: 1000px;\n"
"width: 1000px;\n"
"}"));
        mainDisplay = new QTextBrowser(frame);
        mainDisplay->setObjectName(QString::fromUtf8("mainDisplay"));
        mainDisplay->setGeometry(QRect(290, 150, 361, 91));
        shockCountLabel = new QLabel(frame);
        shockCountLabel->setObjectName(QString::fromUtf8("shockCountLabel"));
        shockCountLabel->setGeometry(QRect(290, 120, 91, 20));
        shockCountEdit = new QLineEdit(frame);
        shockCountEdit->setObjectName(QString::fromUtf8("shockCountEdit"));
        shockCountEdit->setGeometry(QRect(380, 120, 31, 25));
        shockCountEdit->setReadOnly(true);
        stage1Label = new QLabel(frame);
        stage1Label->setObjectName(QString::fromUtf8("stage1Label"));
        stage1Label->setEnabled(true);
        stage1Label->setGeometry(QRect(80, 190, 131, 111));
        stage1Label->setAutoFillBackground(true);
        stage2Label = new QLabel(frame);
        stage2Label->setObjectName(QString::fromUtf8("stage2Label"));
        stage2Label->setEnabled(true);
        stage2Label->setGeometry(QRect(420, 10, 131, 111));
        stage2Label->setAutoFillBackground(true);
        stage3Label = new QLabel(frame);
        stage3Label->setObjectName(QString::fromUtf8("stage3Label"));
        stage3Label->setEnabled(true);
        stage3Label->setGeometry(QRect(730, 190, 131, 111));
        stage3Label->setAutoFillBackground(true);
        stage4Label = new QLabel(frame);
        stage4Label->setObjectName(QString::fromUtf8("stage4Label"));
        stage4Label->setEnabled(true);
        stage4Label->setGeometry(QRect(610, 370, 121, 101));
        stage4Label->setAutoFillBackground(true);
        stage5_1Label = new QLabel(frame);
        stage5_1Label->setObjectName(QString::fromUtf8("stage5_1Label"));
        stage5_1Label->setEnabled(true);
        stage5_1Label->setGeometry(QRect(200, 350, 111, 91));
        stage5_1Label->setAutoFillBackground(true);
        stage5_2Label = new QLabel(frame);
        stage5_2Label->setObjectName(QString::fromUtf8("stage5_2Label"));
        stage5_2Label->setEnabled(true);
        stage5_2Label->setGeometry(QRect(280, 410, 111, 91));
        stage5_2Label->setAutoFillBackground(true);
        stage6Label = new QLabel(frame);
        stage6Label->setObjectName(QString::fromUtf8("stage6Label"));
        stage6Label->setEnabled(true);
        stage6Label->setGeometry(QRect(440, 340, 91, 81));
        stage6Label->setAutoFillBackground(true);
        statusDisplay = new QTextBrowser(centralwidget);
        statusDisplay->setObjectName(QString::fromUtf8("statusDisplay"));
        statusDisplay->setGeometry(QRect(10, 550, 71, 61));
        statusDisplay->setStyleSheet(QString::fromUtf8("background-color: #006500;\n"
"\n"
"/* When lit \n"
"background-color: #35B235;\n"
""));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(50, 530, 61, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        statusLabel->setFont(font);
        shockButton = new QPushButton(centralwidget);
        shockButton->setObjectName(QString::fromUtf8("shockButton"));
        shockButton->setGeometry(QRect(550, 560, 121, 41));
        toggleCprButton = new QPushButton(centralwidget);
        toggleCprButton->setObjectName(QString::fromUtf8("toggleCprButton"));
        toggleCprButton->setGeometry(QRect(160, 560, 121, 41));
        statusDisplay2 = new QTextBrowser(centralwidget);
        statusDisplay2->setObjectName(QString::fromUtf8("statusDisplay2"));
        statusDisplay2->setGeometry(QRect(80, 550, 71, 61));
        statusDisplay2->setStyleSheet(QString::fromUtf8("background-color: #8B0000;\n"
"\n"
"/* When lit \n"
"background-color: #D84141;\n"
""));
        applyElectrodeButton = new QPushButton(centralwidget);
        applyElectrodeButton->setObjectName(QString::fromUtf8("applyElectrodeButton"));
        applyElectrodeButton->setGeometry(QRect(680, 560, 121, 41));
        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(810, 550, 141, 61));
        testButton = new QPushButton(centralwidget);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setGeometry(QRect(290, 560, 121, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 961, 22));
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
        isOk->setText(QString());
        callForHelp->setText(QString());
        connectDevice->setText(QString());
        stepBack->setText(QString());
        analyze->setText(QString());
        startCPR->setText(QString());
        shockCountLabel->setText(QCoreApplication::translate("MainWindow", "Shock Count:", nullptr));
        shockCountEdit->setText(QCoreApplication::translate("MainWindow", "00", nullptr));
        stage1Label->setText(QString());
        stage2Label->setText(QString());
        stage3Label->setText(QString());
        stage4Label->setText(QString());
        stage5_1Label->setText(QString());
        stage5_2Label->setText(QString());
        stage6Label->setText(QString());
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        shockButton->setText(QCoreApplication::translate("MainWindow", "Shock", nullptr));
        toggleCprButton->setText(QCoreApplication::translate("MainWindow", "Toggle CPR", nullptr));
        applyElectrodeButton->setText(QCoreApplication::translate("MainWindow", "Apply Electrode", nullptr));
        powerButton->setText(QCoreApplication::translate("MainWindow", "ON/OFF", nullptr));
        testButton->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
