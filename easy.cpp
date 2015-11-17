#include "easy.h"

void easy::deleteAt(vector<string>&vec,int n)
{
    vector<string>::iterator it = vec.begin()+n;
    vec.erase(it);
}

int easy::StrToInt(string str)
{return atoi(str.c_str());}

string easy::IntToStr(int i)
{
    char t[1024];
    string s;
    sprintf(t,"%d",i);
    s=t;
    return s;
}

