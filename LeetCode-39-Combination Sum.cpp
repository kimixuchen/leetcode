/**
LeetCode-39-Combination Sum
07/03/16 12:02:33
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
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector< vector<int> > > cons(target +1, vector<vector<int>>());
        sort(candidates.begin(), candidates.end());
        cons[0].push_back(vector<int>());
        for(auto score:candidates)
        {
            for(int j=score; j<=target; ++j)
            {
                if(cons[j-score].size() > 0)
                {
                    auto newC = cons[j-score];
                    for(auto& e : newC)
                    {
                        e.push_back(score);
                    }
                    cons[j].insert(cons[j].end(), newC.begin(), newC.end());
                }
            }
        }
        return cons[target];
    }
};
