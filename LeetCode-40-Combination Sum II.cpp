/**
LeetCode-40-Combination Sum II
23/03/16 21:29:20
xuchen
**/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
private:
    void dfs(vector< vector<int> > &ans, int remain, int pos, int len, vector<int> &candicates, 
            vector<int> &tmp)
    {
        if(0==remain)
        {
            ans.push_back(tmp);
            return;
        }
        if(remain < 0)
            return;
        
        for(int i=pos; i<len; ++i)
        {
            if(i==pos || candicates[i]!=candicates[i-1])
            {
                remain -= candicates[i];
                tmp.push_back(candicates[i]);
                dfs(ans, remain, i+1, len, candicates, tmp);
                remain += candicates[i];
                tmp.pop_back();
            }
        }
    }
public:
    vector< vector<int> > combinationSum2(vector<int>& candicates, int target) {
        sort(candicates.begin(), candicates.end());
        int len = candicates.size();
        vector< vector<int> > ans;
        vector<int> tmp;
        dfs(ans, target, 0, len, candicates, tmp);
        
        return ans;
    }

};
