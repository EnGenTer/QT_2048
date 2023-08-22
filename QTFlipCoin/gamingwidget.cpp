#include "gamingwidget.h"
#include "ui_gamingwidget.h"

using namespace std;

gamingwidget::gamingwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamingwidget)
{
    ui->setupUi(this);
}

gamingwidget::~gamingwidget()
{
    delete ui;
}

void gamingwidget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
        this->__game_operate(1);
    else if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
        this->__game_operate(2);
    else if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
        this->__game_operate(3);
    else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
        this->__game_operate(4);
    else if (event->key() == Qt::Key_Enter)
        this->__GameInfo.reset();
    this->__game_show();

    if (this->__GameInfo.is_end() == true)
        QMessageBox::information(this, "game over", "game over");
}

void gamingwidget::__game_show()
{
    // 很呆的实现，能不能用字符串代替变量？
    ui->box1->clear();
    ui->box1->append(QString(this->__GameInfo.get_num(0)));
    ui->box2->clear();
    ui->box2->append(QString(this->__GameInfo.get_num(1)));
    ui->box3->clear();
    ui->box3->append(QString(this->__GameInfo.get_num(2)));
    ui->box4->clear();
    ui->box4->append(QString(this->__GameInfo.get_num(3)));
    ui->box5->clear();
    ui->box5->append(QString(this->__GameInfo.get_num(4)));
    ui->box6->clear();
    ui->box6->append(QString(this->__GameInfo.get_num(5)));
    ui->box7->clear();
    ui->box7->append(QString(this->__GameInfo.get_num(6)));
    ui->box8->clear();
    ui->box8->append(QString(this->__GameInfo.get_num(7)));
    ui->box9->clear();
    ui->box9->append(QString(this->__GameInfo.get_num(8)));
    ui->box10->clear();
    ui->box10->append(QString(this->__GameInfo.get_num(9)));
    ui->box11->clear();
    ui->box11->append(QString(this->__GameInfo.get_num(10)));
    ui->box12->clear();
    ui->box12->append(QString(this->__GameInfo.get_num(11)));
    ui->box13->clear();
    ui->box13->append(QString(this->__GameInfo.get_num(12)));
    ui->box14->clear();
    ui->box14->append(QString(this->__GameInfo.get_num(13)));
    ui->box15->clear();
    ui->box15->append(QString(this->__GameInfo.get_num(14)));
    ui->box16->clear();
    ui->box16->append(QString(this->__GameInfo.get_num(15)));

    ui->ScoreNumber->display(this->__GameInfo.get_score());
}

void gamingwidget::__game_operate(int Direction)
{
    this->__GameInfo.game_operate(Direction);
}

int gamingwidget::__game_reset()
{
    this->__GameInfo.reset();
    return 1;
}

//unsigned int gamingwidget::__game_score()
//{
//    return this->__GameInfo.get_score();
//}

