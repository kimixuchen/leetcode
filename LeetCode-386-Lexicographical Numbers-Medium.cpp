/*
LeetCode-386-Lexicographical Numbers
24/11/16 10:32:21
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <set>
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
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        int m = 1;
        while(ret.size()<n)
        {
            ret.push_back(m);
            if(m*10>n)
            {
                while(m%10 == 9)
                {
                    m /= 10;
                }
                m += 1;
                while(m > n)
                {
                    m -= 1;
                    m /= 10;
                    while(m%10 == 9)
                    {
                        m/=10;
                    }
                    m += 1;
                }
            }
            else
            {
                m *= 10;
            }
        }
        return ret;
        
    }
};
