#include "MathHelp.h"

double MathHelp::RandF()
{return (double)(rand()/(double)RAND_MAX);}

double MathHelp::Distance(cordine a, cordine b)
{return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));}

cordine MathHelp::LimitPos(cordine pos)
{
    if (pos.first > 400)
    { pos.first = 400; }
    else if (pos.first < 0)
    { pos.first = 0; }
    if (pos.second>400)
    { pos.second = 400; }
    else
    {
        if (pos.second < 0)
        { pos.second = 0; }
    }
    return pos;
}

cordine MathHelp::MakeNoiseOf(cordine accuratetarget)
{
    srand((unsigned)time(NULL));
    int x = accuratetarget.first;
    int y = accuratetarget.second;
    double randr = AINOISERADIUS*randf();
    double theta = randf() * 2 * XC_PI;
    int tx =(int)( x + randr*cos(theta));
    int ty =(int) (y + randr*sin(theta));
    return cordine(tx, ty);
}

bool MathHelp::NearlyOnline(cordine point, cordine l1, cordine l2)
{
    double d1 = distance(point, l1);
    double d2 = distance(point, l2);
    double d3 = distance(l1, l2);
    return (d1 + d2 + ERRORCOMPENSATION - d3) <= ACCEPETABLEOFFSET;
}
