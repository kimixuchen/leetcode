/**
LeetCode-486-Predict the Winner
2017-01-22 19:16:52
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <set>
using namespace std;

class Solution {
private:
	int search(int start, int end, vector<int>& nums, vector<vector<int>>& dp)
	{
		if(start > end)
			return 0;

		if(start == end)
			return nums[start];

		if(dp[start][end] != INT_MAX)
		{
			return dp[start][end];
		}

		int a = nums[start] - search(start+1, end, nums, dp);
		int b = nums[end] - search(start, end-1, nums, dp);

		dp[start][end] = max(a, b);

		return dp[start][end];

	}
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int gap = search(0, n-1, nums, dp);

        return gap >= 0;
    }
};
