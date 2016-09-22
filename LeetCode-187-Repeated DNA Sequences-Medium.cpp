/**
LeetCode-187-Repeated DNA Sequences
22/09/16 09:01:30
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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> ret;
        int len = s.length();
        for(int i=0; i+9<len; ++i)
        {
            string t = s.substr(i, 10);
            if(m.find(t)!=m.end() && m[t]==1)
            {
                ret.push_back(t);
            }
            m[t]++;
        }
        return ret;
        
    }
};
