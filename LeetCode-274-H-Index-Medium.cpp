/**
LeetCode-274-H-Index
19/10/16 09:25:49
xuchen
**/

#include <iostream>
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
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int h = 0;
        int n = citations.size();
        for(int i=0; i<n; ++i)
        {
            if(citations[i] >= n-i)
            {
                h = n-i;
                break;
            }
        }
        
        return h;
        
    }
};
