/*
LeetCode-398-Random Pick Index
28/11/16 09:48:14
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

const int MAX = 0x3f3f3f3f;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int k = 0;
        int pos = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i]==target)
            {
                k++;
                int r = rand()%k;
                if(r==0)
                {
                    pos = i;
                }
            }
        }
        
        return pos;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
