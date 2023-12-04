#include <QRandomGenerator>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "analysisStage.h"
#include "shockStage.h"
#include "cprStage.h"
#include "responsivenessStage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    victim = new Victim();
    aed = new AED(victim);
    currentStageIndex = -1;

    connect(ui->powerButton, &QPushButton::clicked, this, &MainWindow::togglePower);
    connect(aed, &AED::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(ui->replaceBatteryButton, &QPushButton::clicked, this, &MainWindow::replaceBattery);
    connect(ui->connectCableButton, &QPushButton::clicked, [this](){aed->connectCable();});
    connect(ui->applyCprPadzButton, &QPushButton::clicked, this, [this](){dynamic_cast<ElectrodeStage*>(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE))->applyCprPads();});
    connect(ui->applyPediPadzButton, &QPushButton::clicked, this, [this](){dynamic_cast<ElectrodeStage*>(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE))->applyPediPads(victim);});
    connect(ui->applyUpperFrontPadButton, &QPushButton::clicked, [this](){dynamic_cast<ElectrodeStage*>(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE))->applyUpperPad(victim);});
    connect(ui->applyLowerBackPadButton, &QPushButton::clicked, [this](){dynamic_cast<ElectrodeStage*>(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE))->applyLowerPad(victim);});
    connect(ui->toggleCprButton, &QPushButton::clicked, this, &MainWindow::startCPR);
    connect(aed, &AED::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed, &AED::updateStatusDisplay, this, &MainWindow::updateStatusDisplay);
    connect(aed, &AED::updateCable, this, &MainWindow::updateCable);
    connect(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &AEDStage::updateButtonStatus, this, &MainWindow::updateButtonStatus);
    connect((ElectrodeStage*)aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &ElectrodeStage::connectPads, this, &MainWindow::connectPads);
    connect(aed->getStages().at((int)StageOrderInSequence::RESPONSIVENESS_STAGE), &AEDStage::nextStage, this, &MainWindow::incrementStageSequence);
    connect(aed->getStages().at((int)StageOrderInSequence::HELP_STAGE), &AEDStage::nextStage, this, &MainWindow::incrementStageSequence);
    connect(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &AEDStage::nextStage, this, &MainWindow::incrementStageSequence);
    connect(aed->getStages().at((int)StageOrderInSequence::ANALYSIS_STAGE), &AEDStage::nextStage, this, &MainWindow::incrementStageSequence);
    connect(aed->getStages().at((int)StageOrderInSequence::SHOCK_STAGE), &AEDStage::nextStage, this, &MainWindow::incrementStageSequence);
    connect(aed->getStages().at((int)StageOrderInSequence::CPR_STAGE), &AEDStage::nextStage, this, &MainWindow::incrementStageSequence);
    connect(aed->getStages().at((int)StageOrderInSequence::RESPONSIVENESS_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::HELP_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::ELECTRODE_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::ANALYSIS_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::SHOCK_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::CPR_STAGE), &AEDStage::updateDisplay, this, &MainWindow::updateTextDisplay);
    connect(ui->victimAwakensOrHelpArrivedButton, &QPushButton::clicked, this, &MainWindow::victimAwakensOrHelpArrived);
    connect(aed, &AED::updateStatusDisplay, this, &MainWindow::updateStatusDisplay);
    connect((AnalysisStage*)aed->getStages().at((int)StageOrderInSequence::ANALYSIS_STAGE), &AnalysisStage::updateECGDisplay, this, &MainWindow::updateECGDisplay);
    connect(aed->getStages().at((int)StageOrderInSequence::CPR_STAGE), &AEDStage::updateCompressionPicture, this, &MainWindow::updateCPRDisplay);
    connect((ShockStage*)aed->getStages().at((int)StageOrderInSequence::SHOCK_STAGE), &ShockStage::incrementShockCount, this, &MainWindow::updateShockCount);
    connect((ShockStage*)aed->getStages().at((int)StageOrderInSequence::SHOCK_STAGE), &ShockStage::drainBattery, this, &MainWindow::drainBattery);
    connect(aed, &AED::updateStageOrder, this, &MainWindow::updateCurrentStageIndex);

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
    QPixmap isOkayImage("../../res/stages/isOkayImage.png");
    QPixmap helpImage("../../res/stages/callForHelpImage.png");
    QPixmap electrodeImage("../../res/stages/attachElectrodeImage.png");
    QPixmap standBackImage("../../res/stages/standBackImage.png");
    QPixmap cprImage1("../../res/stages/cprImage1.png");
    QPixmap cprImage2("../../res/stages/cprImage2.png");
    QPixmap indicatorImage("../../res/stages/indicatorImage.png");
    ui->stage1Label->setPixmap(isOkayImage);
    ui->stage2Label->setPixmap(helpImage);
    ui->stage3Label->setPixmap(electrodeImage);
    ui->stage4Label->setPixmap(standBackImage);
    ui->stage5_1Label->setPixmap(cprImage1);
    ui->stage5_2Label->setPixmap(cprImage2);
    ui->stage6Label->setPixmap(indicatorImage);

    ui->connectCableButton->setEnabled(false);
    ui->applyUpperFrontPadButton->setEnabled(false);
    ui->applyLowerBackPadButton->setEnabled(false);
    ui->toggleCprButton->setEnabled(false);

    updateECGDisplay(BLANK);
    ui->battery->setText("");
    updateCPRDisplay(CompressionStatus::NO_COMPRESSIONS);

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
            if (victim->getIsUpperPadOn() && victim->getIsUpperPadOn()){
                currentStageIndex = (int)StageOrderInSequence::ELECTRODE_STAGE;
                incrementStageSequence();
            }
            else {
                updateTextDisplay("STAY CALM.");
                QThread::sleep(2);
                updateIndicators(0);
                incrementStageSequence();
            }
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
        updateECGDisplay(BLANK);
        clearIndicators();
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

void MainWindow::blinkIndicators() {
    for (int i = 0; i <= indicators.length(); i++) {
        updateIndicators(i);
        QThread::msleep(700);
    }
}

void MainWindow::clearIndicators() {
    for (int i = 0; i < indicators.length(); i++) {
        indicators.at(i)->setChecked(false);
        indicators.at(i)->repaint();
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

        if (aed->getBatteryLevel() < 1) {
            togglePower();
            stopCPR();
            aed->setStatus(FAIL);
            ui->powerButton->setEnabled(false);
            aed->setCurrentStage(aed->getStages().at((int)StageOrderInSequence::RESPONSIVENESS_STAGE));
        }
    }
}

void MainWindow::replaceBattery() {
    qDebug() << "Replacing Battery...";
    aed->setBatteryLevel(100);
    ui->powerButton->setEnabled(true);

    QThread::sleep(1);

    if (aed->isPoweredOn()) {
        updateBatteryDisplay();
    }

    qDebug() << "Battery Successfully Replaced.";
}

void MainWindow::updateCurrentStageIndex(StageOrderInSequence stageIndex) {
    currentStageIndex = (int)stageIndex;
}

void MainWindow::incrementStageSequence() {
    if(aed->isPoweredOn()){
        drainBattery();
        ++currentStageIndex;
        if (ui->textDisplay->toPlainText() == "STOP CPR.") {
            currentStageIndex = (int)StageOrderInSequence::ANALYSIS_STAGE;
            indicators.at((int)StageOrderInSequence::CPR_STAGE)->setChecked(false);
            indicators.at((int)StageOrderInSequence::CPR_STAGE)->repaint();
        }
        if (currentStageIndex == (int)StageOrderInSequence::CPR_STAGE) {
            ui->toggleCprButton->setEnabled(true);
        }
        aed->setCurrentStage(aed->getStages().at(currentStageIndex));
        updateIndicators(currentStageIndex);
        aed->getCurrentStage()->start();
    }
}

void MainWindow::victimAwakensOrHelpArrived() {
    if (aed->isPoweredOn()) {
        qDebug() << "The victim has awoken or help has arrived!";
        togglePower();
        ui->applyCprPadzButton->setEnabled(true);
        ui->applyPediPadzButton->setEnabled(true);
        ui->applyUpperFrontPadButton->setEnabled(false);
        ui->applyLowerBackPadButton->setEnabled(false);
    }
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
        QThread::sleep(1);
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
}

void MainWindow::updateECGDisplay(HEART_RATE victimDiagnosis) {
    QPixmap blankECG("../../res/ecg/ecg.jpg");
    QPixmap normalECG("../../res/ecg/ecg_normal.jpg");
    QPixmap vtachECG("../../res/ecg/ecg_vtach.jpg");
    QPixmap vfibECG("../../res/ecg/ecg_vfib.jpg");
    QPixmap asystoleECG("../../res/ecg/ecg_asystole.jpg");
    switch(victimDiagnosis) {
        case BLANK:
            ui->ecgDisplay->setPixmap(blankECG);
            break;
        case NORMAL:
            ui->ecgDisplay->setPixmap(normalECG);
            break;
        case VTACH:
            ui->ecgDisplay->setPixmap(vtachECG);
            break;
        case VFIB:
            ui->ecgDisplay->setPixmap(vfibECG);
            break;
        case ASYSTOLE:
            ui->ecgDisplay->setPixmap(asystoleECG);
            break;
    }
    ui->ecgDisplay->setScaledContents(true);
    ui->ecgDisplay->repaint();
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
        //NO COMPRESSIONS DISPLAY
        ui->compressionLabel1->setStyleSheet("background-color: white");
        ui->compressionLabel2->setStyleSheet("background-color: white");
        ui->compressionLabel3->setStyleSheet("background-color: white; border-top: 1px solid black; border-bottom: 1px solid black;");
    }

    ui->compressionLabel1->repaint();
    ui->compressionLabel2->repaint();
    ui->compressionLabel3->repaint();
}

void MainWindow::updateShockCount() {
    aed->incrementShockCount();
    ui->shockCountEdit->setText(QString::number(aed->getShockCount()));
    ui->shockCountEdit->repaint();
    updateTextDisplay(QString::number(aed->getShockCount()) + " SHOCK(S) DELIVERED.");
}

void MainWindow::updateButtonStatus(BUTTON button){
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
}

void MainWindow::startCPR(){
    CprStage* cprStage = dynamic_cast<CprStage*>(aed->getStages().at((int)StageOrderInSequence::CPR_STAGE));
    QTimer* startTimer = cprStage->getStartTimer();

    startTimer->start(2000);
    ui->toggleCprButton->setEnabled(false);
}

void MainWindow::stopCPR() {
    CprStage* cprStage = dynamic_cast<CprStage*>(aed->getStages().at((int)StageOrderInSequence::CPR_STAGE));
    QTimer* startTimer = cprStage->getStartTimer();
    QTimer* stopTimer = cprStage->getStopTimer();

    startTimer->stop();
    stopTimer->stop();
    cprStage->stopCompression();
    updateTextDisplay("");
    ui->toggleCprButton->setEnabled(false);
}
