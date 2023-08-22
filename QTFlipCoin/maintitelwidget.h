#ifndef MAINTITELWIDGET_H
#define MAINTITELWIDGET_H

#include <QWidget>


namespace Ui {
class maintitelwidget;
}

class maintitelwidget : public QWidget
{
    Q_OBJECT

public:
    explicit maintitelwidget(QWidget *parent = nullptr);
    ~maintitelwidget();

signals:
    void quit_game();
    void start_game();

private slots:
    void on_quitbutten_released();

    void on_startbutten_released();

private:
    Ui::maintitelwidget *ui;
};

#endif // MAINTITELWIDGET_H
