/*
LeetCode-367-Valid Perfect Square
18/11/16 10:20:36
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
    bool isPerfectSquare(int num) {
        int len = 0;
        for(int n = num; n>0; n/=10)
            ++len;
        
        int l = 1, r = pow(10, len/2+1);
        int sq = 0;
        
        while(l<=r)
        {
            long long mid = l+(r-l)/2;
            if(mid*mid < num)
            {
                l = mid+1;
            }
            else if(mid*mid > num)
            {
                r = mid-1;
            }
            else
            {
                sq = mid;
                break;
            }
        }
        return sq>0;
    }
};
