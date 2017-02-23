/*
LeetCode-526-Beautiful Arrangement
23/02/17 10:41:43
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
private:
    void search(vector<vector<int>> &candidates, vector<bool> &used, int pos, 
            int &ret, const int &N)
    {
        if(pos > N)
        {
            ++ret;
            return;
        }

        for(int i : candidates[pos])
        {
            if(!used[i])
            {
                used[i] = true;
                search(candidates, used, pos+1, ret, N);
                used[i] = false;
            }
        }
        
        return;
    }
public:
    int countArrangement(int N) {
        vector<vector<int>> candidates(N+1, vector<int>());
        
        for(int i=1; i<=N; ++i)
        {
            for(int j=1; j<=N; ++j)
            {
                if(i%j==0 || j%i==0)
                    candidates[i].push_back(j);
            }
        }
        
        vector<bool> used(N+1, false);
        int ret = 0;
        
        search(candidates, used, 1, ret, N);
        
        return ret;
        
    }
};
