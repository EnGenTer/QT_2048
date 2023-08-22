#ifndef GAME_H
#define GAME_H

#include <random>
#include <string>

using namespace std;

enum {
    COL = 4, // 因为客户端界面的按钮已经写死了，所以这里的变量实际上也不能修改
    ROW = COL, // 因为代码原因，绑定必须是正方形格子
    START_NUM = COL,
    MULTI_INPUT = (COL << 1) - 1
};

class game
{
public:
    game();
    bool game_operate(int Direction = 0);
    void reset();
    const char* get_num(int idx);
    const char* get_score();
    bool is_end();

private:
    unsigned int __Sum, __Round;

    unsigned int __Direction;
    int __EmptyNum;
    vector<unsigned int> __List;

    int __move(int BeginIdx);
    int __next_idx(int CurIdx);
    int __random_input();
};

#endif // GAME_H
