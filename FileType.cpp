#include "FileType.h"

FileType::FileType(string path,vector<ReadPar> readvar,int company)
{
     this->file=new fstream;
     file->open(path.c_str(),ios::in);
     if (!file)//读取错误
     {ReadError();}
     this->path=path;
     this->readvar=readvar;
     this->company=company;
     PreProcessing();//读取完毕
}

FileType::~FileType()
{delete file;}

void FileType::ReadFile()
{
    char buf[company];
    while (!file->eof())//按位读入内容，直到结束符
    {
        file->read(buf,company);
        for(auto i:readvar)
        {
            if(buf==i.first)
            {i.second();}
        }
    }
    SuppleExplanation();
}
