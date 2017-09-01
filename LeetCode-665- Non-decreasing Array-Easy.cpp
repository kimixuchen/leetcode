/*
LeetCode-665- Non-decreasing Array
2017-09-01
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
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        
        int pos1 = -1;
        int oddCount = 0;
        bool isOk = true;
        for(int i=1; i<n; i++) {
            if(nums[i]<nums[i-1]) {
                ++oddCount;
                if(oddCount > 1){
                    isOk = false;
                    break;
                }
                else {
                    pos1 = i;
                    int preMin = INT_MIN;
                    if(pos1-2>=0)
                        preMin = nums[pos1-2];
                    int afterMax = INT_MAX;
                    if(pos1+1 < n)
                        afterMax = nums[pos1+1];
                    if(preMin > nums[pos1] && afterMax < nums[pos1-1]) {
                        isOk = false;
                        break;
                    }
                }
            }
        }
        
        return isOk;
    }
};
