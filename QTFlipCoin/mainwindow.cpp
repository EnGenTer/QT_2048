#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gaming->hide();
    ui->tabWidget->tabBar()->hide();

    connect(ui->maintitel, &maintitelwidget::start_game, [=](){
        ui->maintitel->hide();
        ui->tabWidget->widget(1)->show();
        ui->gaming->show();
    });

    connect(ui->maintitel, &maintitelwidget::destroyed, [=](){
        this->close();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

