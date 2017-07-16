/*
 * Leetcode 643-Maximum Average Subarray I
 */
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
    double findMaxAverage(vector<int>& nums, int k) {
        int _max = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(i<k) {
                sum += nums[i];
                _max = sum;
            }
            else{
                sum -= nums[i-k];
                sum += nums[i];
                _max = max(_max, sum);
            }
        }
        return _max*1.0/k;
    }
};

