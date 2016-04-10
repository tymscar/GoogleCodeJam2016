#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int T, counting;
string S;

int isItGood(string s)
{
    for(int i=0;i<s.length();i++)
        if(s[i]!='+')
            return 0;
    return 1;
}

void flipIncluding(int number)
{
    counting++;
    char temp;
    if(number == 0) //S[0]
    {
        if(S[number]== '+')
            S[number] = '-';
        else
            S[number] = '+';
    }
    else
    {
        //S[1]
        for(int i=0;i<=number/2;i++)
        {
            temp = S[number-i];
            S[number-i] = S[0+i];
            S[0+i] = temp;

            if(S[number-i] == '+')
                S[number-i] = '-';
            else
                S[number-i] = '+';
            if(S[0+i] == '+')
                S[0+i] = '-';
            else
                S[0+i] = '+';
        }
    }
    if(number %2 ==0)
            {
                if(S[number/2] == '+')
                    S[number/2] = '-';
                else
                    S[number/2] = '+';
            }
}

void mainLogic(string s)
{
        if(s.length()==1)
        {
            if(s[0]=='-')
                flipIncluding(0);
        }
        if(s.length()==2)
        {
            if(s[0]==s[1] && s[0] == '-')
                flipIncluding(1);
            if(s[0]!=s[1] && s[0] == '-')
                flipIncluding(0);
            if(s[0]!=s[1] && s[1] == '-')
            {
                flipIncluding(0);
                flipIncluding(1);
            }
        }
        if(s.length()>=3)
        {
        for(int i=1;i<s.length();i++)
        {
            if(i==1) //if its first
            {
                if(s[i] != s[i-1])
                    flipIncluding(i-1);
            }
            else
            {
                if(i==s.length()-1) //if its last
                {
                    if(s[i] != s[i-1])
                        flipIncluding(i-1);
                    if(s[i] == '-')
                        flipIncluding(i);
                }
                else //if its in between
                {
                    if(s[i] != s[i-1])
                    flipIncluding(i-1);
                }
            }
        }
        }
}

int main()
{
    ifstream inputFile;
    inputFile.open("input.txt");
    ofstream outputFile;
    outputFile.open("output.txt");
    inputFile>>T;
    for(int i=1;i<=T;i++)
    {
        counting = 0;
        inputFile>>S;
        mainLogic(S);
        outputFile<<"Case #"<<i<<": "<<counting<<endl;
    }
    return 0;
}
