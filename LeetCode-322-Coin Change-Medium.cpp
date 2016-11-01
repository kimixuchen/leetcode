/*
LeetCode-322-Coin Change
01/11/16 09:37:32
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
    int bisearch(vector<int> &coins, int amount)
    {
        int left = 0;
        int right = coins.size();
        int mid;
        while(left < right)
        {
            mid = left + (right-left)/2;
            if(coins[mid]>amount)
                right = mid;
            else
                left = mid+1;
        }
        
        return left-1;
    }
    
    int search(vector<int> &coins, int amount, unordered_map<int, int> &map)
    {
        if(map.find(amount) != map.end())
            return map[amount];
        int pos = bisearch(coins, amount);
        if(pos==-1)
            map[amount] = -1;
        else
        {
            int minrest = INT_MAX;
            for(int i=pos; i>=0; --i)
            {
                int rest = search(coins, amount-coins[i], map);
                if(rest!=-1)
                    minrest = min(minrest, rest);
            }
            if(minrest==INT_MAX)
                map[amount] = -1;
            else
                map[amount] = 1+minrest;
        }
        
        return map[amount];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        unordered_map<int, int> map;
        map[0] = 0;
        
        return search(coins, amount, map);
    }
};
