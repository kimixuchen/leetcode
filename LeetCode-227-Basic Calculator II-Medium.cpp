/**
LeetCode-227-Basic Calculator II
11/10/16 08:07:39
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        queue<int> RPN;
        stack<char> ops;
        ops.push('#');
        unordered_map<char, int> opm;
        opm['+'] = -1;
        opm['-'] = -2;
        opm['*'] = -3;
        opm['/'] = -4;
        unordered_map<char, int> oppri;
        oppri['*'] = 2;
        oppri['/'] = 2;
        oppri['+'] = 1;
        oppri['-'] = 1;
        oppri['#'] = INT_MIN;
        
        int num = 0;
        for(int i=0; i<s.length(); ++i)
        {
            if(s[i]==' ')
                continue;
            
            if(s[i]>='0' && s[i]<='9')
            {
                num *= 10;
                num += s[i] - '0';
                if(i+1>=s.length() || s[i+1]<'0' || s[i+1]>'9')
                {
                    RPN.push(num);
                    num = 0;
                }
            }
            else
            {
                while(oppri[ops.top()] >= oppri[s[i]])
                {
                    RPN.push(opm[ops.top()]);
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
        while(ops.top() != '#')
        {
            RPN.push(opm[ops.top()]);
            ops.pop();
        }
        
        int ret = 0;
        stack<int> nums;
        while(!RPN.empty())
        {
            if(RPN.front()>=0)
            {
                nums.push(RPN.front());
            }
            else
            {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                switch(RPN.front())
                {
                case -1:
                    nums.push(a+b);
                    break;
                case -2:
                    nums.push(a-b);
                    break;
                case -3:
                    nums.push(a*b);
                    break;
                case -4:
                    nums.push(a/b);
                    break;
                }
            }
            RPN.pop();
        }
        ret = nums.top();
        
        return ret;
        
    }
};
