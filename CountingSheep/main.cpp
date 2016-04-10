#include <iostream>
#include <fstream>
using namespace std;

int T,counter;
int infinitedetect;
int N,newn;
int digits[10];
ifstream dateinput;
ofstream dateoutput;

void verifyDigits(int x)
{
    do
    {
        digits[x%10]++;
        x = x/10;
    }while(x != 0);
}

int isItDone()
{
    int sum=0;
    for(int i=0;i<=9;i++)
    {
        if(digits[i] != 0)
            sum++;
    }
    if(sum == 10)
        return 1;
    else
        return 137;
}

void Counting(int n, int tryno)
{
    infinitedetect = 1;
    counter = 1;
    for(int i=0; i<=9;i++)
    {
        digits[i] = 0;
    }

    do
    {
        newn = n*counter;
        verifyDigits(newn);
        infinitedetect++;
        counter++;
    }while(isItDone()!=1 && infinitedetect < 1000000);

    if(infinitedetect > 14998)
        dateoutput<<"Case #"<<tryno<<": "<<"INSOMNIA"<<endl;
    else
        dateoutput<<"Case #"<<tryno<<": "<<newn<<endl;
}

int main()
{

    dateinput.open("input.txt");
    dateoutput.open("output.txt");
    dateinput>>T;
    for(int i=1; i<=T;i++)
    {
        dateinput>>N;
        Counting(N,i);
    }
    return 0;
}
