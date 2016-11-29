/*
LeetCode-401-Binary Watch
29/11/16 09:14:05
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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
private:
    const int MAXTIME = 11*60+59;
    const int MINITESPERHOUR = 60;
    
    int getOnes(int n)
    {
        int counter = 0;
        while(n > 0)
        {
            ++counter;
            n &= (n-1);
        }
        return counter;
    }
    
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        
        for(int i=0; i<=MAXTIME; ++i)
        {
            int h = i/MINITESPERHOUR;
            int m = i%MINITESPERHOUR;
            
            int h1s = getOnes(h);
            int m1s = getOnes(m);
            
            if(h1s+m1s == num)
            {
                string time;
                time += to_string(h);
                time += ":";
                if(m<10)
                    time += "0"+to_string(m);
                else
                    time += to_string(m);
                
                ret.push_back(time);
            }
        }
        
        return ret;
        
    }
};
