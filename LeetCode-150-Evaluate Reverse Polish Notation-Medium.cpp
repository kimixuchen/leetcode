/**
LeetCode-150-Evaluate Reverse Polish Notation
14/09/16 15:11:04
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
    int evalRPN(vector<string>& tokens) {
        stack<int> s_nums;
        int res = 0;
        
        for(int i=0; i<tokens.size(); ++i)
        {
            if(tokens[i].length()==1 && !isdigit(tokens[i][0]))
            {
                int b = s_nums.top();
                s_nums.pop();
                int a = s_nums.top();
                s_nums.pop();
                switch(tokens[i][0])
                {
                    case '+':
                        a = a+b;
                        break;
                    case '-':
                        a = a-b;
                        break;
                    case '*':
                        a = a*b;
                        break;
                    case '/':
                        a = a/b;
                        break;
                    default:
                        break;
                }
                
                s_nums.push(a);
            }
            else
            {
                s_nums.push(1.0 * atoi(tokens[i].c_str()));
            }
        }
        
        return s_nums.top();
        
    }
};
