/*
LeetCode-504-Base 7
12/02/17 10:31:00
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <priority_queue>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string convertTo7(int num) {
        int flag = 1;
        if(num < 0)
        {
            flag = -1;
            num = -num;
        }
        
        if(num == 0)
            return "0";
        
        int _max = 9;   
        string ret;
        int firstpos = -1;
        for(int i=_max; i>=0; --i)
        {
            int b = pow(7, i);
            if(num < b)
                ret.append("0");
            else
            {
                if(firstpos==-1)
                    firstpos = _max-i;
                int d = num/b;
                num = num%b;
                ret.append(to_string(d));
            }
        }
        ret = ret.substr(firstpos, ret.length()-firstpos);
        
        if(flag == -1)
            ret = "-"+ret;
        
        return ret;
    }
};
