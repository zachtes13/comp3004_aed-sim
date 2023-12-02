#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    aed = new AED();
    victim = new Victim();
    currentStageIndex = -1;

    connect(ui->powerButton, &QPushButton::clicked, this, &MainWindow::togglePower);
    connect(ui->connectCableButton, &QPushButton::clicked, [this](){aed->connectCable();});
    connect(ui->replaceBatteryButton, &QPushButton::clicked, this, &MainWindow::replaceBattery);
    connect(ui->victimAwakensOrHelpArrivedButton, &QPushButton::clicked, this, &MainWindow::victimAwakensOrHelpArrived);

    connect(ui->applyCprPadzButton, &QPushButton::clicked, this, [this](){dynamic_cast<ElectrodeStage*>(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE))->applyCprPads();});
    connect(ui->applyPediPadzButton, &QPushButton::clicked, this, [this](){dynamic_cast<ElectrodeStage*>(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE))->applyPediPads(victim);});
    connect(ui->applyUpperFrontPadButton, &QPushButton::clicked, [this](){dynamic_cast<ElectrodeStage*>(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE))->applyUpperPad(victim);});
    connect(ui->applyLowerBackPadButton, &QPushButton::clicked, [this](){dynamic_cast<ElectrodeStage*>(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE))->applyLowerPad(victim);});

    connect(aed, &AED::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed, &AED::updateStatusDisplay, this, &MainWindow::updateStatusDisplay);
    connect(aed, &AED::updateCable, this, &MainWindow::updateCable);
    connect(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &AEDStage::updateUIButton, this, &MainWindow::updateUIButton);
    connect(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &AEDStage::connectPads, this, &MainWindow::connectPads);
    connect(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &AEDStage::nextStage, this, &MainWindow::incrementStageSequence);
    connect(aed->getStages().at((int)StageOrderInSequence::RESPONSIVENESS_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::HELP_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::ANALYSIS_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::SHOCK_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::CPR_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);

    initialize();
}

MainWindow::~MainWindow() {
    delete ui;
    delete aed;
    delete victim;
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

    ui->connectCableButton->setEnabled(false);
    ui->applyUpperFrontPadButton->setEnabled(false);
    ui->applyLowerBackPadButton->setEnabled(false);

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
            aed->togglePower();
            blinkIndicators();
            QThread::sleep(1);
            updateTextDisplay("STAY CALM.");
            QThread::sleep(1);
//            incrementStageSequence();
//            incrementStageSequence();
//            incrementStageSequence();
//            incrementStageSequence();
//            incrementStageSequence();
//            incrementStageSequence();
//            incrementStageSequence();
//            incrementStageSequence();
//            incrementStageSequence();
        }
    }
    else {
        qDebug() << "Powering Off";
        updateTextDisplay("POWER OFF.");
        ui->battery->setText("");
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
    ui->applyCprPadzButton->setEnabled(true);
    ui->applyPediPadzButton->setEnabled(true);
    ui->applyUpperFrontPadButton->setEnabled(false);
    ui->applyLowerBackPadButton->setEnabled(false);
}

void MainWindow::connectPads(){
    qDebug() << "Connecting the pads to the AED device.";

    aed->setPadsPluggedIn(true);
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

void MainWindow::updateUIButton(BUTTON button){
    if(button == CPR){
        ui->applyCprPadzButton->setEnabled(false);
    }else if(button == PEDI){
        ui->applyPediPadzButton->setEnabled(false);
    }else if(button == UPPER){
        ui->applyUpperFrontPadButton->setEnabled(!ui->applyUpperFrontPadButton->isEnabled());
    }else if(button == LOWER){
        ui->applyLowerBackPadButton->setEnabled(!ui->applyLowerBackPadButton->isEnabled());
    }
}

void MainWindow::updateCable(bool isEnabled){
    ui->connectCableButton->setEnabled(isEnabled);
//    if (!isEnabled){
//        togglePower();
//    }
}

void MainWindow::triggerAedFailure() {
    if (aed->isPoweredOn()) {
        togglePower();
    }
    ui->battery->setText("");
    updateTextDisplay("");
}
