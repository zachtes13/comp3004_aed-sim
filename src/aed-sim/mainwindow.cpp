#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->powerButton, &QPushButton::clicked, this, &MainWindow::power);

    for (QObject *widget : ui->frame->children()) {
           if (QRadioButton *radioButton = qobject_cast<QRadioButton*>(widget)) {
               radioButtons.append(radioButton);
           }
    }

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::power);

    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    qDebug() << "Initializing";
}


void MainWindow::power()
{
    qDebug() << "Powering On";

//    Everything blinks at the same time
//    for (QObject *widget : ui->frame->children()) {
//       if (QRadioButton *radioButton = qobject_cast<QRadioButton*>(widget)) {
//           radioButton->setAutoExclusive(false);
//           radioButton->setChecked(!radioButton->isChecked());
//           radioButton->setAutoExclusive(true);
//       }
//   }

    if (currentIndex > 0) {
            radioButtons.at(currentIndex - 1)->setChecked(false);
        }

        radioButtons.at(currentIndex)->setChecked(true);
        currentIndex = (currentIndex + 1) % radioButtons.size();
}
