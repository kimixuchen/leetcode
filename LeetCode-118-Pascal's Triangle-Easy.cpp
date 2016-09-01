/**
LeetCode-118-Pascal's Triangle
01/09/16 08:02:53
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <map>
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for(int i=0; i<numRows; ++i)
        {
            vector<int> curRow;
            curRow.push_back(1);
            for(int j=1; j<i; ++j)
                curRow.push_back(ret[i-1][j-1]+ret[i-1][j]);
            if(i > 0)
                curRow.push_back(1);
            ret.push_back(curRow);
        }
        return ret;
    }
};
