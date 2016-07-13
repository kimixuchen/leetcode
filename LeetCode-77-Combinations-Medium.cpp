/**
LeetCode-77-Combinations
13/07/16 09:48:34
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
private:
    void search(vector<vector<int>>&ret, vector<int>&cell, int counter
            , int begin, int n)
    {
        if(counter == 0)
        {
            ret.push_back(cell);
            return;
        }
        
        for(int i=begin; i<=n-counter+1; ++i)
        {
            cell.push_back(i);
            search(ret, cell, counter-1, i+1, n);
            cell.pop_back();
        }
        
        return;
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> cell;
        
        search(ret, cell, k, 1, n);
        
        return ret;
    }

};
