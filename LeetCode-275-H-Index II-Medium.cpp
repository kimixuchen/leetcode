/**
LeetCode-275-H-Index II
19/10/16 09:40:35
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
        int h = 0;
        int n = citations.size();
        int left=0, right = n-1, mid;
        
        while(left <= right)
        {
            mid = (left+right)/2;
            if(citations[mid] >= n-mid)
            {
                h = n-mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        
        return h;
    }
};
