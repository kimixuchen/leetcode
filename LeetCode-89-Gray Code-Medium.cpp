/**
LeetCode-89-Gray Code
15/07/16 10:50:51
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
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        for(int i=0; i < 1<<(n); ++i)
        {
            ret.push_back(i ^ (i>>1));
        }
        return ret;
        
    }
};
