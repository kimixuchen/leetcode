/**
LeetCode-44-Wildcard Matching
17/04/16 16:14:50
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
public:
    bool isMatch(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();
        int pos1=0, pos2=0;
        int posS = -1;
        int ss = -1;
        while(pos1<len1)
        {
            if(p[pos2]=='?' || s[pos1]==p[pos2])
            {
                ++pos1;
                ++pos2;
            }
            else if(p[pos2]=='*')
            {
                ss = pos1;
                posS = pos2;
                ++pos2;
            }
            else if(posS > -1)
            {
                pos2 = posS+1;
                ++ss;
                pos1 = ss;
            }
            else
                return false;
        }
        while(p[pos2]=='*')
            ++pos2;
        
        return pos2==len2;
        
    }
};

int main()
{
    Solution s;
    string ss, t;
    cout<<s.isMatch("", "***")<<endl;
    cout<<s.isMatch("a", "")<<endl;
    while(cin>>ss)
    {
        cin>>t;
        cout<<(bool)s.isMatch(ss, t)<<endl;
    }
    return 0;
}
