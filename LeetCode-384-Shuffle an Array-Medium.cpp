/*
LeetCode-384-Shuffle an Array
23/11/16 11:57:37
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
private:
    vector<int> originalnums;
    vector<int> opnums;
    
public:
    Solution(vector<int> nums) {
        this->originalnums = nums;
        this->opnums = nums;
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return originalnums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=opnums.size()-1; i>0; --i)
        {
            int n = rand()%(i+1);
            swap(opnums[n], opnums[i]);
        }
        return opnums;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
