#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->powerButton, &QPushButton::clicked, this, &MainWindow::power);
    connect(ui->testButton, &QPushButton::clicked, this, &MainWindow::test);

    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    qDebug() << "Initializing";

    for (QObject *widget : ui->frame->children()) {
       if (QRadioButton *radioButton = qobject_cast<QRadioButton*>(widget)) {
           radioButton->raise();
           radioButtons.append(radioButton);
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


void MainWindow::power()
{
    qDebug() << "Powering On";
    ui->mainDisplay2->append("POWER ON");

    // Will make all the radio buttons blink once when powering on.
    for (QObject *widget : ui->frame->children()) {
       if (QRadioButton *radioButton = qobject_cast<QRadioButton*>(widget)) {
           radioButton->setAutoExclusive(false);
           radioButton->setChecked(!radioButton->isChecked());
           radioButton->setAutoExclusive(true);
       }
   }

    QTimer::singleShot(850, [this](){
       for (QObject *widget : ui->frame->children()) {
           if (QRadioButton *radioButton = qobject_cast<QRadioButton*>(widget)) {
               radioButton->setAutoExclusive(false);
               radioButton->setChecked(!radioButton->isChecked());
               radioButton->setAutoExclusive(true);
           }
        }
    });

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::blink);

    timer->start(1000);
}

// Will keep select the nexr radio button in a clock-wise direction
void MainWindow::blink()
{
    qDebug() << "Blinking";

    if (currentIndex > 0) {
            radioButtons.at(currentIndex - 1)->setChecked(false);
   }

    radioButtons.at(currentIndex)->setChecked(true);
    currentIndex = (currentIndex + 1) % radioButtons.size();
}

// Temp test function
void MainWindow::test()
{
    qDebug() << "Testing";

}
