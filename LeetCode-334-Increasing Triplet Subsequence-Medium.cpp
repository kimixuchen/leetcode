/*
LeetCode-334-Increasing Triplet Subsequence
10/11/16 10:49:25
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
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstmin=INT_MAX, secondmin=INT_MAX;
        int n = nums.size();
        for(int i=0; i<n; ++i)
        {
            if(nums[i]<=firstmin)
                firstmin = nums[i];
            else if(nums[i]<secondmin)
                secondmin = nums[i];
            else if(nums[i]>secondmin)
                return true;
        }
        return false;
    }
};
