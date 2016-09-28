/**
LeetCode-216-Combination Sum III
28/09/16 10:17:08
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
private:
    void search(int k, int base, int n, vector<vector<int>> &ret, vector<int> &cur)
    {
        if(k==0 && n==0)
        {
            ret.push_back(cur);
            return;
        }
        
        if(9-base+1 < k)
            return;
        int min = (2*base+k-1)*k/2;
        int max = (2*9+k-1)*k/2;
        if(min>n || max<n)
            return;
        
        for(int i=base; i<=9; ++i)
        {
            cur.push_back(i);
            search(k-1, i+1, n-i, ret, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> cur;
        search(k, 1, n, ret, cur);
        return ret;
        
    }
};
