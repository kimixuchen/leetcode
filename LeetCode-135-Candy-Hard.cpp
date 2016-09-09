/**
LeetCode-135-Candy
09/09/16 08:13:34
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
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
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        int sum = 0;
        for(int i=0; i<n-1; ++i)
        {
            if(ratings[i+1]>ratings[i])
                candies[i+1] = candies[i]+1;
        }
        for(int i=n-1; i>0; --i)
        {
            if(ratings[i-1]>ratings[i])
                candies[i-1] = max(candies[i-1], candies[i]+1);
        }
        for(int i=0; i<n; ++i)
            sum += candies[i];
        
        return sum;
    }
};
