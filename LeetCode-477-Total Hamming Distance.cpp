/*
LeetCode-477-Total Hamming Distance
18/12/16 10:37:20
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

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> pos0(32, 0);
        vector<int> pos1(32, 0);
        
        for(int i=0; i<32; ++i)
        {
            for(auto num : nums)
            {
                if(((num>>i)&1) == 0)
                    pos0[i]++;
                else
                    pos1[i]++;
            }
        }
        
        int distance = 0;
        for(int i=0; i<32; ++i)
        {
            for(auto num : nums)
            {
                if(((num>>i)&1) == 0)
                    distance += pos1[i];
                else
                    distance += pos0[i];
            }
        }
        distance /= 2;
        
        return distance;
        
    }
};
