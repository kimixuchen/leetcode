/*
LeetCode-555-Split Assembled Strings
17/04/17 09:44:07
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

using namespace std;

class Solution {
private:
    string getRev(string s)
    {
        reverse(s.begin(), s.end());
        return s;
    }
public:
    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        
        string ret="A";
        
        for(int i=0; i<n; ++i)
        {
            string mid;
            
            for(int j=1; j<n; ++j)
            {
                mid += max(strs[j], getRev(strs[j]));
            }
            
            for(int j=0; j<=strs[0].size(); ++j)
            {
                string prefix = strs[0].substr(0, j);
                string suffix = strs[0].substr(j);
                string tmp = max(suffix+mid+prefix, getRev(prefix)+mid
                        +getRev(suffix));
                ret = max(ret, tmp);
            }
            rotate(strs.begin(), strs.begin()+1, strs.end());
        }
        
        return ret;
        
    }
};
