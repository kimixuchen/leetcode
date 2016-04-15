/**
LeetCode-43-Mutiply Strings
15/04/16 08:54:44
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
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> s1(len1, 0);
        vector<int> s2(len2, 0);
        
        for(int i=0; i<len1; ++i)
            s1[i] = num1[i]-'0';
        for(int i=0; i<len2; ++i)
            s2[i] = num2[i]-'0';
        
        int len3 = len1+len2;
        vector<int> ans(len3, 0);
        for(int i=len2-1; i>=0; --i)
        {
            int c=0;
            int pos = len1+i;
            for(int j=len1-1; j>=0; --j)
            {
                int m = s1[j] * s2[i] + c;
                m += ans[pos];
                ans[pos] = m%10;
                c = m/10;
                --pos;
            }
            ans[pos] = c;
        }
        int pos1=0;
        for( ; pos1<len3-1; ++pos1)
            if(ans[pos1] != 0)
                break;
        
        string ret(len3-pos1, '0');
        for(int i=pos1; i<len3; ++i)
            ret[i-pos1] = ans[i]+'0';
        
        return ret;
    }
};

int main()
{
    Solution s1;
    cout<<s1.multiply("123", "456")<<endl;
    cout<<s1.multiply("999", "999")<<endl;
    cout<<s1.multiply("123", "0")<<endl;

    return 0;
}
