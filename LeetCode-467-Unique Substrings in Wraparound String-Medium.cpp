/*
LeetCode-467-Unique Substrings in Wraparound String
04/12/16 11:41:54
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

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.length()==0)
            return 0;
        const int MOD = 26;
        vector<int> lens(p.length(), 0);
        vector<int> used(26, 0);
        int ret = 0;
        
        lens[0] = 1;
        ret += 1;
        used[p[0]-'a'] = 1;
        for(int i=1; i<p.length(); ++i)
        {
            if((p[i]+MOD-p[i-1])%MOD == 1)
            {
                lens[i] = lens[i-1]+1;
            }
            else
            {
                lens[i] = 1;
            }
            if(used[p[i]-'a'] < lens[i])
            {
                ret += lens[i] - used[p[i]-'a'];
                used[p[i]-'a'] = lens[i];
            }
        }
        return ret;
        
    }
};
