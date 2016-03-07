/**
LeetCode-38-Count and Say
07/03/16 08:58:27
xuchen
**/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

class Solution {

    string nextSay(string s)
    {
        char base = s[0];
        string nexts = "";
        int count = 1;
        char buffer[4] = {'0', '1', '2', '3'};
        for(int i=1; i<s.length(); i++)
        {
            if(s[i] == base)
            {
                ++count;
            }
            else
            {
                nexts+=buffer[count];
                nexts+=base;
                base = s[i];
                count = 1;
            }
        }
        nexts+=buffer[count];
        nexts+=base;
        return nexts;
    }
public:
    string countAndSay(int n) {
        string strSay = "1";
        for(int i=1; i<n; i++)
        {
            strSay = nextSay(strSay);
        }
        return strSay;
    }
};

int main()
{
    Solution *s = new Solution();
    int n;
    while(cin>>n)
    {
        cout<<s->countAndSay(n)<<endl;
    }
    return 0;
}
