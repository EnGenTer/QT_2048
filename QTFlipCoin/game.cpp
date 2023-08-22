#include "game.h"

game::game()
{
    this->reset();
}

bool game::game_operate(int Direction)
{
    this->__Direction = Direction;
    if (Direction == 0) return 1;

    for (int curidx = -1; curidx >= -4; --curidx) {
        this->__move(this->__next_idx(curidx));
    }

    int randnum;
    for (int i = 0; i < (this->__EmptyNum / MULTI_INPUT); ++i)
        randnum = this->__random_input();
    randnum = this->__random_input();

    ++this->__Round;

    return true;
}

void game::reset()
{
    srand(int(time(nullptr)));
    this->__EmptyNum = ROW * COL;
    this->__Sum = 0;
    this->__Direction = 0;
    this->__List.clear();
    this->__List.resize(16, 0);
    this->__Round = 0;
}

const char *game::get_num(int idx)
{
    unsigned int shiftnum = this->__List[idx];
    if (shiftnum == 0)
        return "";
    return to_string(1 << shiftnum).c_str();
}

const char *game::get_score()
{
    return to_string(this->__Sum).c_str();
}

bool game::is_end()
{
    return __EmptyNum < 0;
}

int game::__move(int BeginIdx)
{
    // 类似冒泡
    int curidx, nextidx;
    for (int cidx = 0; cidx < COL - 1; ++cidx) { // 写到这才想起来可能边框不是正方形的
        curidx = BeginIdx;
        for (int ccidx = cidx; ccidx < COL - 1; ++ccidx) {
            nextidx = this->__next_idx(curidx);
            if (this->__List[curidx] == 0 && this->__List[nextidx] != 0) {
                this->__List[curidx] = this->__List[nextidx];
                this->__List[nextidx] = 0;
            }
            else if (this->__List[curidx] == this->__List[nextidx] && this->__List[curidx] != 0){
                this->__List[nextidx] = 0;
                ++this->__EmptyNum;
                this->__Sum += ++__List[curidx];
            }
            curidx = nextidx;
        }
    }

    return 1;
}

int game::__next_idx(int CurIdx)
{
    switch (this->__Direction) {
    case 1: // up
        if (CurIdx < 0) return -CurIdx - 1;
        else return CurIdx + COL;
    case 2: // down
        if (CurIdx < 0) return CurIdx + ROW * COL;
        else return CurIdx - COL;
    case 3: // left
        if (CurIdx < 0) return (-CurIdx - 1) * COL;
        else return CurIdx + 1;
    case 4: // right
        if (CurIdx < 0) return (-CurIdx) * COL - 1;
        else return CurIdx - 1;
    default:
        return 0;
    }
}

int game::__random_input()
{
    if (this->__EmptyNum == 0){
        this->__EmptyNum = -999;
        return 0;
    }

    int curidx = 0;
    int randidx = rand() % this->__EmptyNum;
    while (this->__List[curidx] != 0)
        ++curidx;
    for (; randidx > 0; --randidx)
        ++curidx;
        while (this->__List[curidx] != 0)
            ++curidx;
    if (curidx >= COL * ROW)
        return 0;
    this->__List[curidx] = (rand() & 1) + 1;
    --this->__EmptyNum;

    return 1;
}
