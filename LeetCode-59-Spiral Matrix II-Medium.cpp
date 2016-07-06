/**
LeetCode-59-Spiral Matrix II
05/07/16 20:10:54
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cn = n;
        vector<vector<int>> ret;
        for(int i=0; i<n; ++i)
        {
            vector<int> row(n, 0);
            ret.push_back(row);
        }
        
        int x=0, y=0;
        int cur = 1;
        while(cn>0)
        {
            for(int i=y; i<y+cn; ++i)
                ret[x][i] = cur++;
            for(int i=x+1; i<x+cn; ++i)
                ret[i][y+cn-1] = cur++;
            for(int i=y+cn-2; i>=y; --i)
                ret[x+cn-1][i] = cur++;
            for(int i=x+cn-2; i>x; --i)
                ret[i][y] = cur++;
            
            cn-=2;
            x++;
            y++;
        }    
        
        return ret;
    }
};
