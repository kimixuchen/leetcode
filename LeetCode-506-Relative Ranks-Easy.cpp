/*
LeetCode-506-Relative Ranks
05/02/17 10:59:20
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

bool cmp(const int &a, const int &b)
{
    return a>b;
}

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> cpnums(nums);
        sort(cpnums.begin(), cpnums.end(), cmp);
        unordered_map<int, int> numpos;
        for(int i=0; i<cpnums.size(); ++i)
        {
            numpos[cpnums[i]] = i;
        }
        vector<string> ret;
        
        for(int i : nums)
        {
            if(numpos[i]==0)
            {
                ret.push_back("Gold Medal");
            }
            else if(numpos[i]==1)
            {
                ret.push_back("Silver Medal");
            }
            else if(numpos[i]==2)
            {
                ret.push_back("Bronze Medal");
            }
            else
            {
                ret.push_back(to_string(numpos[i]+1));
            }
        }
        return ret;
    }
};
