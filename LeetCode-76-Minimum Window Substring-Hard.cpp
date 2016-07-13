/**
LeetCode-75-Sort Colors
13/07/16 08:27:26
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(auto c : t)
        {
            map[c]++;
        }
        int head=0, begin=0, end=0, d=INT_MAX;
        int counter = t.length();
        
        while(end < s.length())
        {
            if(map[s[end++]]-- > 0)
                counter--;
            
            while(counter == 0)
            {
                if(end-begin < d)
                    d = end - (head=begin);
                
                if(map[s[begin++]]++ == 0)
                    counter++;
            }
        }
        if(d<INT_MAX)
            return s.substr(head, d);
        else
            return "";
        
    }
};
