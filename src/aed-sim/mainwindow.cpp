#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    aed = new AED();

    connect(ui->powerButton, &QPushButton::clicked, this, &MainWindow::togglePower);
    connect(ui->testButton, &QPushButton::clicked, this, &MainWindow::test);
    connect(aed, &AED::updateDisplay, this, &MainWindow::updateTextDisplay);

    initialize();
}

MainWindow::~MainWindow() {
    delete ui;
    delete aed;
}

void MainWindow::initialize() {
    qDebug() << "Initializing";

    for (QObject *widget : ui->frame->children()) {
       if (QRadioButton *indicator = qobject_cast<QRadioButton*>(widget)) {
           indicator->raise();
           indicators.append(indicator);
       }
    }

    // Load images
    QPixmap image1("../../res/stages/isOkayImage.png");
    QPixmap image2("../../res/stages/callForHelpImage.png");
    QPixmap image3("../../res/stages/attachElectrodeImage.png");
    QPixmap image4("../../res/stages/standBackImage.png");
    QPixmap image5_1("../../res/stages/cprImage1.png");
    QPixmap image5_2("../../res/stages/cprImage2.png");
    QPixmap image6("../../res/stages/indicatorImage.png");
    ui->stage1Label->setPixmap(image1);
    ui->stage2Label->setPixmap(image2);
    ui->stage3Label->setPixmap(image3);
    ui->stage4Label->setPixmap(image4);
    ui->stage5_1Label->setPixmap(image5_1);
    ui->stage5_2Label->setPixmap(image5_2);
    ui->stage6Label->setPixmap(image6);
}


void MainWindow::togglePower() {
    if (!aed->isPoweredOn()) {
        bool isSelfTestPassed = aed->selfTest();

        if (isSelfTestPassed) {
            qDebug() << "Powering On";
            updateTextDisplay("POWER ON.");
            aed->togglePower();
            blinkIndicators();
            QThread::sleep(1);
            updateTextDisplay("STAY CALM.");
        }
    }
    else {
        qDebug() << "Powering Off";
        updateTextDisplay("POWER OFF.");
        aed->togglePower();
        QThread::sleep(1);
        updateTextDisplay("");
    }
}

// Will keep selecting the next radio button in a clock-wise direction.
void MainWindow::blinkIndicators() {
    for (int i = 0; i <= indicators.length(); i++) {
        if (i > 0) {
                indicators.at(i - 1)->toggle();
                indicators.at(i - 1)->repaint();
        }
        if (i < indicators.length()) {
            indicators.at(i)->toggle();
            indicators.at(i)->repaint();
            QThread::msleep(700);
        }
    }
}

// Temp test function
void MainWindow::test() {
    qDebug() << "Testing";
}

void MainWindow::updateTextDisplay(QString newTextDisplayValue) {
    ui->textDisplay->setText(newTextDisplayValue);
    ui->textDisplay->repaint();
}
