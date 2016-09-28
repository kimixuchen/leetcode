/**
LeetCode-215-Kth Largest Element in an Array
28/09/16 09:24:17
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
private:
    int select(vector<int>& nums, int i, int j, int k)
    {
        int pivot = nums[i];
        int pos = i;
        int tmp;
        for(int k=i+1; k<=j; ++k)
        {
            if(nums[k]>=pivot)
            {
                tmp = nums[pos+1];
                nums[pos] = nums[k];
                nums[k] = tmp;
                ++pos;
            }
        }
        nums[pos] = pivot;
        if(pos-i+1 == k)
            return pivot;
        if(pos-i+1 > k)
            return select(nums, i, pos-1, k);
        else 
            return select(nums, pos+1, j, k-pos+i-1);
    }

    void shuffle(vector<int>& nums)
    {
        for(int i=1;  i<nums.size(); ++i)
        {
            int r = rand()%(i+1);
            swap(nums[i], nums[r]);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cnums = nums;
        shuffle(cnums);
        return select(cnums, 0, cnums.size()-1, k);
    }
};
