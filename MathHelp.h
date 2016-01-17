#pragma once
#include <utility>
#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define ACCEPETABLEOFFSET 0.64
#define ERRORCOMPENSATION 0.0000001
#define AINOISERADIUS 3
#define XC_PI 3.1415926

using namespace std;

typedef pair<int, int> cordine;//坐标
typedef pair<cordine, cordine> linevertex;

class MathHelp
{
public:
    static double Distance(cordine a, cordine b);//求两点之间距离
    static double RandF();//取双精度随机数
    static bool NearlyOnline(cordine point,cordine l1, cordine l2);//确认三点共线
    cordine LimitPos(cordine);//求坐标极限
    cordine MakeNoiseOf(cordine);//坐标噪化
};


