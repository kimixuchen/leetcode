#include <iostream>
#include <alogrithm>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        k = abs(k);
        for(int i=0; i<n; ++i)
        {
        	sum = nums[i];
        	for(int j=i+1; j<n; ++j)
        	{
        		sum += nums[j];
        		if((sum==0 && k==0) || (k!=0 && sum%k==0))
        			return true;
        	}
        }
        return false;
    }
};