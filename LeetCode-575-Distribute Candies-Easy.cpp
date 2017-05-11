/*
LeetCode-575-Distribute Candies
11/05/17 10:28:55
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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kinds;
        for(int c : candies)
            kinds.insert(c);
        
        return kinds.size()>=candies.size()/2 ? candies.size()/2 : kinds.size();
    }
};
