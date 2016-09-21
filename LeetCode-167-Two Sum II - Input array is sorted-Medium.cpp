/**
LeetCode-167-Two Sum II - Input array is sorted
21/09/16 09:06:10
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pos1=0, pos2=numbers.size()-1;
        int sum;
        while(pos1<pos2)
        {
            sum = numbers[pos1] + numbers[pos2];
            if(sum == target)
            {
                break;
            }
            else if(sum < target)
            {
                ++pos1;
            }
            else if(sum > target)
            {
                --pos2;
            }
        }
        
        vector<int> ret;
        ret.push_back(pos1+1);
        ret.push_back(pos2+1);
        
        return ret;
    }
};
