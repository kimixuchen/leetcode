/**
LeetCode-119-Pascal's Triangle II
01/09/16 08:11:15
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
    vector<int> getRow(int rowIndex) {
        vector<int> kRow(rowIndex+1, 1);
        for(int i=0; i<rowIndex+1; ++i)
        {
            int pre = 0;
            int tmp = 0;
            for(int j=0; j<i; ++j)
            {
                tmp = kRow[j];
                kRow[j] += pre;
                pre = tmp;
            }
        }
        return kRow;
    }
};
