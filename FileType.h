#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef void (*voidfun)();
typedef pair<string,voidfun> ReadPar;

class FileType
{
public:
    FileType(string path, vector<ReadPar> readvar, int company);
    ~FileType();
    void ReadFile();
    vector<ReadPar> readvar;

protected:
    virtual void ReadError(){}
    virtual void PreProcessing(){}
    virtual void SuppleExplanation(){}

    string path;
    int company;//读取的单位长度
    fstream *file;

};
