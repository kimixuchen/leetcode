#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<cstring>

using namespace std;

const int MAX = 0x3f3f3f3f;

int main()
{
    string s;
    const int M = 15;
    const int FN = 5;
    int numsF[FN];
    memset(numsF, 0, sizeof(numsF));
    while(cin>>s)
    {
        for(int i=0; i<FN; ++i)
        {
            if(s[i]=='1')
                numsF[i]++;
        }
    }
    int _min = MAX;
    for(int i=0; i<FN; ++i)
        _min = min(_min, numsF[i]);

    cout<<_min<<endl;

    return 0;
}