#pragma once
#include <math.h>

class Jumping
{
    /*无论angle为何值，
     * v0*sin(angle)同JumpV，v0*cos(angle)同MoveV，必然相等
     * 均可替换进行表达式折叠*/

public:
    Jumping(float JumpV,float MoveV);
    float GetX(int t);
    float GetY(int t);
    void ChangeJumpV(float JumpV, int t);
    void ChangeMoveV(float MoveV,int t);
    //使用时请严格注意！！这个函数不保留现场
    float MaxX();
    float MaxY();

private:
    void Update();

    float JumpV;
    float MoveV;
    float v0;
    static constexpr float angle=3.14/2;
    //跳跃中竖直速度与水平速度夹角必然是九十度，如果出现特殊情况需要改变偏转角则删除static const，然后对之前折叠的表达式进行展开
    static const int g=10;
    int MaxTime;
    //保留的现场
    float dx=0;
    float dy=0;
    float dt=0;
};
