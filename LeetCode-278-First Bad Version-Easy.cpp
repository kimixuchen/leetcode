/**
LeetCode-278-First Bad Version
19/10/16 09:46:57
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

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1, right=n, mid;
        while(left<right)
        {
            mid = left + (right-left)/2;
            if(isBadVersion(mid))
                right = mid;
            else
                left = mid+1;
        }
        
        return left;
        
    }
};
