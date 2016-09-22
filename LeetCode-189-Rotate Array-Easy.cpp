/**
LeetCode-189-Rotate Array
22/09/16 09:26:41
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
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0 || k%nums.size()==0)
            return;
        
        k %= nums.size();
        int tmp;
        int count = 0;
        int start = 0;
        while(count < nums.size())
        {
            int i=start;
            pre = nums[i];
            do
            {
                i = (i+k)%nums.size();
                tmp = nums[i];
                nums[i] = pre;
                pre = tmp;
                ++count;
            }while(i!=start);
            ++start;
        }
        
    }
};
