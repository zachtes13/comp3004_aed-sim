#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    aed = new AED();
    currentStageIndex = -1;

    connect(ui->powerButton, &QPushButton::clicked, this, &MainWindow::togglePower);
    connect(aed, &AED::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(ui->replaceBatteryButton, &QPushButton::clicked, this, &MainWindow::replaceBattery);
    connect(aed->getStages().at((int)StageOrderInSequence::RESPONSIVENESS_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::HELP_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::ANALYSIS_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::SHOCK_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::CPR_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(ui->victimAwakensOrHelpArrivedButton, &QPushButton::clicked, this, &MainWindow::victimAwakensOrHelpArrived);
    connect(aed, &AED::updateStatusDisplay, this, &MainWindow::updateStatusDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::CPR_STAGE), &AEDStage::updateCompressionPicture, this, &MainWindow::updateCPRDisplay);

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

    ui->battery->setText("");

    //Timer code, every 5 seconds call drainBattery() function.
    QTimer* batteryTimer = new QTimer();
    connect(batteryTimer, &QTimer::timeout, this, &MainWindow::drainBattery);
    batteryTimer->start(5000);
}

void MainWindow::togglePower() {
    if (!aed->isPoweredOn()) {
        bool isSelfTestPassed = aed->selfTest();
        if (isSelfTestPassed) {
            qDebug() << "Powering On";
            updateTextDisplay("POWER ON.");
            QString batteryText = QString::number(aed->getBatteryLevel());
            ui->battery->setText("Battery: " + batteryText + "%");
            updateCPRDisplay(CompressionStatus::NO_COMPRESSIONS);
            aed->togglePower();
            blinkIndicators();
            QThread::sleep(1);
            updateTextDisplay("STAY CALM.");
            QThread::sleep(2);
            incrementStageSequence();
            incrementStageSequence();
            incrementStageSequence();
            incrementStageSequence();
            incrementStageSequence();
            incrementStageSequence();
            incrementStageSequence();
            incrementStageSequence();
            incrementStageSequence();
        }
    }
    else {
        qDebug() << "Powering Off";
        updateTextDisplay("POWER OFF.");
        ui->battery->setText("");
        updateCPRDisplay(CompressionStatus::NO_COMPRESSIONS);
        aed->togglePower();
        QThread::sleep(1);
        updateTextDisplay("");
    }
}

void MainWindow::updateIndicators(int index) {
    if (index > 0) {
            indicators.at(index - 1)->setChecked(false);
            indicators.at(index - 1)->repaint();
    }
    if (index < indicators.length()) {
        indicators.at(index)->setChecked(true);
        indicators.at(index)->repaint();
    }
}

// Will keep selecting the next radio button in a clock-wise direction.
void MainWindow::blinkIndicators() {
    for (int i = 0; i <= indicators.length(); i++) {
        updateIndicators(i);
        QThread::msleep(700);
    }
}

void MainWindow::updateTextDisplay(QString newTextDisplayValue) {
    ui->textDisplay->setText(newTextDisplayValue);
    ui->textDisplay->repaint();
}

void MainWindow::updateBatteryDisplay() {
    QString batteryText = "Battery: " + QString::number(aed->getBatteryLevel()) + "%";
    ui->battery->setText(batteryText);
    ui->battery->repaint();
}

void MainWindow::drainBattery() {

    if (aed->isPoweredOn()) {
        aed->drainBattery();
        updateBatteryDisplay();

        //battery is dead
        if (aed->getBatteryLevel() < 1) {
            togglePower(); //turn off the device.
            aed->setStatus(FAIL);
            ui->powerButton->setEnabled(false); //Disable the power button (our functionality currently does not allow the swapping of batteries).
        }
    }
}

void MainWindow::replaceBattery() {
    qDebug() << "Replacing Battery...";
    aed->setBatteryLevel(100);

    QThread::sleep(1);

    if (aed->isPoweredOn()) {
        updateBatteryDisplay();
    }

    qDebug() << "Battery Successfully Replaced.";
}

void MainWindow::incrementStageSequence() {
    drainBattery();
    ++currentStageIndex;
    if (currentStageIndex > (int)StageOrderInSequence::CPR_STAGE) {
        currentStageIndex = (int)StageOrderInSequence::ANALYSIS_STAGE;
        indicators.at((int)StageOrderInSequence::CPR_STAGE)->setChecked(false);
        indicators.at((int)StageOrderInSequence::CPR_STAGE)->repaint();
    }
    aed->setCurrentStage(aed->getStages().at(currentStageIndex));
    updateIndicators(currentStageIndex);
    aed->getCurrentStage()->start();
}

void MainWindow::victimAwakensOrHelpArrived() {
    if (aed->isPoweredOn()) {
        qDebug() << "The Victim has awoken or help has arrived!";
        togglePower();
    }
}

void MainWindow::updateStatusDisplay(STATUS newStatus) {
    if (newStatus == PASS) {
        ui->statusDisplay->setStyleSheet("background-color: #35B235;");
        updateTextDisplay("UNIT OK.");
        QThread::sleep(2);
    }
    else if (newStatus == FAIL) {
        ui->statusDisplay->setStyleSheet("background-color: #D84141;");
        updateTextDisplay("UNIT FAILED.");
        QThread::sleep(2);
        triggerAedFailure();
    }
    ui->statusDisplay->repaint();
}

void MainWindow::triggerAedFailure() {
    if (aed->isPoweredOn()) {
        togglePower();
    }
    ui->battery->setText("");
    updateTextDisplay("");
    qDebug() << "User adjusts cable.";
}


void MainWindow::updateCPRDisplay(CompressionStatus compressionValue) {

    if (compressionValue == CompressionStatus::GOOD_COMPRESSIONS) {
        //GOOD COMPRESSIONS DISPLAY
        ui->compressionLabel1->setStyleSheet("background-color: black");
        ui->compressionLabel2->setStyleSheet("background-color: black");
        ui->compressionLabel3->setStyleSheet("background-color: black; border-top: 1px solid white;");
    } else if (compressionValue == CompressionStatus::BAD_COMPRESSIONS) {
        //BAD COMPRESSIONS DISPLAY
        ui->compressionLabel1->setStyleSheet("background-color: black");
        ui->compressionLabel2->setStyleSheet("background-color: white");
        ui->compressionLabel3->setStyleSheet("background-color: white; border-top: 1px solid black; border-bottom: 1px solid black;");
    } else {
        ui->compressionLabel1->setStyleSheet("background-color: white");
        ui->compressionLabel2->setStyleSheet("background-color: white");
        ui->compressionLabel3->setStyleSheet("background-color: white; border-top: 1px solid black; border-bottom: 1px solid black;");

    }

    ui->compressionLabel1->repaint();
    ui->compressionLabel2->repaint();
    ui->compressionLabel3->repaint();

}

