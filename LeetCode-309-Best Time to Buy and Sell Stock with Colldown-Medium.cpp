/*
LeetCode-309-Best Time to Buy and Sell Stock with Colldown
25/10/16 09:44:30
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
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        
        vector<int> s0(prices.size(), 0);
        vector<int> s1(prices.size(), 0);
        vector<int> s2(prices.size(), 0);
        s1[0] = -prices[0];
        s2[0] = INT_MIN;
        
        for(int i=1; i<prices.size(); ++i)
        {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s0[i-1]-prices[i], s1[i-1]);
            s2[i] = s1[i-1] + prices[i];
        }
        
        return max(s0[prices.size()-1], s2[prices.size()-1]);
    }
};
