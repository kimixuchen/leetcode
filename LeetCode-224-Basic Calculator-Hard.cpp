/**
LeetCode-224-Basic Calculator
10/10/16 09:15:21
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
        unordered_map<char, int> opm;
        opm['+'] = -1;
        opm['-'] = -2;
        ops.push('#');
        int num=0;
        for(int i=0; i<s.length(); ++i)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                num *= 10;
                num += s[i]-'0';
                if(i+1>=s.length() || s[i+1]<'0' || s[i+1]>'9')
                {
                    RPN.push(num);
                    num = 0;
                }
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                if(ops.top()!='(' && ops.top()!='#')
                {
                    RPN.push(opm[ops.top()]);
                    ops.pop();
                    ops.push(s[i]);
                }
                else
                    ops.push(s[i]);
            }
            else if(s[i]=='(')
            {
                ops.push(s[i]);
            }
            else if(s[i]==')')
            {
                while(ops.top()!='(')
                {
                    RPN.push(opm[ops.top()]);
                    ops.pop();
                }
                ops.pop();
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
                int a, b;
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                if(RPN.front() == -1)
                    nums.push(a+b);
                else
                    nums.push(a-b);
            }
            RPN.pop();
        }
        ret = nums.top();
        
        return ret;
        
    }
};
