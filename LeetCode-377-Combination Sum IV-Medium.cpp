/*
LeetCode-377-Combination Sum IV
21/11/16 19:06:04
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
private:
    unordered_map<int, int> map;
    int search(vector<int>& nums, int target, int cur)
    {
        if(map.find(cur)!=map.end())
            return map[cur];
        
        if(cur == target)
            return 1;
        
        int sum = 0;
        for(int i : nums)
        {
            if(cur+i <= target)
                sum += search(nums, target, cur+i);
        }
        
        map[cur] = sum;
        return sum;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return search(nums, target, 0);
        
    }
};
