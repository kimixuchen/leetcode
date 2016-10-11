/**
LeetCode-229-Majority Element II
11/10/16 10:40:15
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int candidate1, candidate2;
        int count1, count2;
        if(nums.size()==0)
            return ret;
        
        candidate1 = candidate2 = nums[0];
        count1 = count2 = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(candidate1 == nums[i])
                ++count1;
            else if(candidate2 == nums[i])
                ++count2;
            else if(count1==0){
                count1 = 1;
                candidate1 = nums[i];
            }
            else if(count2==0){
                count2 = 1;
                candidate2 = nums[i];
            }
            else{
                --count1;
                --count2;
            }
        }
        count1=count2=0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(candidate1==nums[i])
                ++count1;
            else if(candidate2==nums[i])
                ++count2;
        }
        if(count1>nums.size()/3)
            ret.push_back(candidate1);
        if(count2>nums.size()/3 && candidate1!=candidate2)
            ret.push_back(candidate2);
        
        return ret;
        
    }
};
