#include "maintitelwidget.h"
#include "ui_maintitelwidget.h"

#include <QDebug>

maintitelwidget::maintitelwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::maintitelwidget)
{
    ui->setupUi(this);
}

maintitelwidget::~maintitelwidget()
{
    delete ui;
}

void maintitelwidget::on_quitbutten_released()
{
    emit destroyed();
}

void maintitelwidget::on_startbutten_released()
{
    emit start_game();
}
