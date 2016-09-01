/**
LeetCode-123-Best Time to Buy and Sell Stock III
01/09/16 09:18:45
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <map>
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
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        
        vector<int> fwd(len);
        vector<int> bwd(len);
        int sum = 0;
        int profit = INT_MIN;
        for(int i=1; i<len; ++i)
        {
            sum += (prices[i]-prices[i-1]);
            profit = max(profit, sum);
            fwd[i] = max(fwd[i], profit);
            if(sum < 0)
                sum = 0;
        }
        sum = 0;
        profit = INT_MIN;
        for(int i=len-2; i>=0; --i)
        {
            sum += (prices[i+1]-prices[i]);
            profit = max(profit, sum);
            bwd[i] = max(bwd[i], profit);
            if(sum < 0)
                sum = 0;
        }
        int maxprofit = INT_MIN;
        for(int i=0; i<len; ++i)
        {
            maxprofit = max(maxprofit, fwd[i]+bwd[i]);
        }
        
        return maxprofit;
    }
};
