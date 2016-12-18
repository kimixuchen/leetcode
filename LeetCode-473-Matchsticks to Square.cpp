/*
LeetCode-473-Matchsticks to Square
18/12/16 10:47:17
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

bool cmp(const int &a, const int &b)
{
    return a>b;
}

class Solution {
private:
    bool check(vector<int> &nums, int edge)
    {
        int sum = 0;
        bool flag = true;
        for(int i=0; i<nums.size(); ++i)
        {
            sum += nums[i];
            if(sum==edge)
                sum = 0;
            if(sum>edge)
            {
                flag = false;
                break;
            }
        }
        return flag;
    }

    bool overflow(vector<int> &nums, int edge, int pos)
    {
        int sum = 0;
        bool flag = false;
        for(int i=0; i<pos; ++i)
        {
            sum += nums[i];
            if(sum==edge)
                sum = 0;
            if(sum>edge)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }

    bool search(vector<int> &nums, int edge, int pos)
    {
        if(pos==nums.size()-1 && check(nums, edge))
            return true;
        if(overflow(nums, edge, pos))
            return false;
        
        bool flag = false;
        for(int i=pos+1; i<nums.size(); ++i)
        {
            swap(nums[pos+1], nums[i]);
            if(search(nums, edge, pos+1))
            {
                flag = true;
            }
            swap(nums[pos+1], nums[i]);
            if(flag)
                break;
        }
        
        return flag;
    }
public:
    bool makesquare(vector<int>& nums) {
        int perimeter = 0;
        int edge = 0;
        
        sort(nums.begin(), nums.end(), cmp);
        for(int num : nums)
            perimeter += num;
        if(perimeter%4 != 0)
            return false;
        edge = perimeter/4;
        if(nums.size()<4 || nums[0]>edge)
            return false;
        
        if(search(nums, edge, 0))
            return true;
        else
            return false;
        
    }
};
