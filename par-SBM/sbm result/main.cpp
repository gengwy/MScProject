#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    fstream in("resultZ.dat");
    const int labelsize=9319;
    const int maxLable=1000;
    int *cnt=new int[labelsize];
    for(int i=0;i<labelsize;i++) cnt[i]=0;

    int **labelArr=new int*[labelsize];
    for(int i=0;i<labelsize;i++)
    {
        labelArr[i]=new int[maxLable];
    }

    string line;
    int id,label;

    while(!in.eof())
    {
        getline(in,line);
        sscanf(line.c_str(),"%d %d",&id,&label);
        labelArr[label][cnt[label]]=id;
        cnt[label]++;
    }

    ofstream out("./out");
    for(int i=0;i<labelsize;i++)
    {

        for(int j=0;j<cnt[i];j++)
        {
            out<<labelArr[i][j]<<"    ";
        }
        out<<endl;
    }

//    for(int i=0;i<labelsize;i++)
//    {
//        delete [] &labelArr[i][0];
//    }
//    delete [] &labelArr[0][0];
//    delete []cnt;
    return 0;
}
