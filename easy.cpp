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

vector<string> easy::Split(string o_str,string fenge)//这个还是好使的
{
    vector<string> str_list;
    int comma_n = 0;
    while(1)
    {
        string tmp_s = "";//整一个缓存的字符串
        const char *ccfengge=fenge.c_str();
        comma_n = o_str.find(ccfengge);//查找分隔符第一次出现的位置
        if(comma_n==-1)//要是没找到的话
        {
            str_list.push_back(o_str);//把剩下的全整进去
            break;
        }
        tmp_s = o_str.substr( 0, comma_n );//将这一块截断
        o_str.erase(0,comma_n+fenge.length());//将这一块抹去
        str_list.push_back(tmp_s);//将截断出来的字符加入容器
    }
    return str_list;
}

