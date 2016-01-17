#pragma once

using namespace std;
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

class easy
{
public:
    template<typename T>
    static void deleteAt(vector<T>&vec,int n);
    static int StrToInt(string str);
    static string IntToStr(int i);
    static vector<string> Split(string o_str,string fenge);
};


