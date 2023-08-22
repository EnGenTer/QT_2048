#ifndef GAMINGWIDGET_H
#define GAMINGWIDGET_H

#include <QWidget>
#include <vector>
#include <QTextBrowser>
#include <QString>
#include <QKeyEvent>
#include <QMessageBox>

#include "game.h"

namespace Ui {
class gamingwidget;
}

using namespace std;

class gamingwidget : public QWidget
{
    Q_OBJECT

public:
    explicit gamingwidget(QWidget *parent = nullptr);
    ~gamingwidget();

    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::gamingwidget *ui;
    // 想了下，出于对可拓展性和debug考虑，需要对实际功能实现和展示界面做一个分离，因此单独将游戏内容独立成文件
    game __GameInfo{};

    void __game_show();

    void __game_operate(int Direction);

    int __game_reset();

//    unsigned int __game_score();

    // 为什么添加下一行之后可能会报分配错误？
//    vector<QTextBrowser*> __BoxList{};
};

#endif // GAMINGWIDGET_H
