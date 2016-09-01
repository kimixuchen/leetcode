/**
LeetCode-121-Best Time to Buy and Sell Stock
01/09/16 09:05:12
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
        int profit = INT_MIN;
        int sum = 0;
        for(int i=1; i<prices.size(); ++i)
        {
            sum += (prices[i]-prices[i-1]);
            profit = max(sum, profit);
            if(sum < 0)
                sum = 0;
        }
        return max(profit, 0);
        
    }
};
