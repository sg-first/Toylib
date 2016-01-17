#include "Jumping.h"

Jumping::Jumping(float JumpV,float MoveV)
{
    this->JumpV=JumpV;
    this->MoveV=MoveV;
    Update();
}

float Jumping::GetX(int t)
{
    if(t>MaxTime)
    {return -1;}
    return dx+(MoveV*(t-dt));
}

float Jumping::GetY(int t)
{
    if(t>MaxTime)
    {return -1;}
    return dy+(JumpV*(t-dt))-((g*(t-dt)*(t-dt))/2)/*==(v0*(t-dt)*sin(angle))-((g*(t-dt)*(t-dt))/2)*/;
}

float Jumping::MaxX()//使用时请严格注意！！这个函数不保留现场
{
    return ((v0*v0)*sin(2*angle))/g;
    //TAT懒得优化了，可以通过导入公式优化成有JmupV、MoveV的形式。不过不是更新参数，所以那点性能提升也没用。就放那吧
}

float Jumping::MaxY()//使用时请严格注意！！这个函数不保留现场
{return (JumpV*JumpV)/(2*g);}

void Jumping::ChangeJumpV(float JumpV,int t)
{
    this->JumpV=JumpV;
    this->dt=t;//保留时间
    this->dy=GetY(t);//通过已经经过的时间保留之前已经经过的竖直位移
    Update();
}

void Jumping::ChangeMoveV(float MoveV,int t)
{
    this->MoveV=MoveV;
    this->dt=t;//保留时间
    this->dx=GetX(t);//通过已经经过的时间保留之前已经经过的水平位移
    Update();
}

void Jumping::Update()
{
    this->v0=sqrt((JumpV*JumpV)+(MoveV*MoveV));
    if(dy!=0)
    {
        int t1=(JumpV/g)+dt;//上升阶段时间
        int t2=sqrt((2*(MaxY()+dy))/g);//下降阶段时间
        this->MaxTime=t1+t2;
    }
    else
    {this->MaxTime=(2*JumpV)/g/*==(2*v0*sin(angle))/g*/;}
    //其实前后两个的值应该是一样的，可以并为一个，不过为了演算速度快一点就分头来了
}
