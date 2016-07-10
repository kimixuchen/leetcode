/**
LeetCode-69-Sqrt(x)
10/07/16 07:59:25
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    int mySqrt(int x) {
        const int _MAX = 46340;
        int ans = 0;
        int left = 0;
        int c, x1;
        x1 = x;
        c = 0;
        while(x1/10 > 0)
        {
            ++c;
            x1 /= 10;
        }
        int right = 1;
        for(int i=0; i < c/2+1; ++i)
        {
            right *= 10;
        }
        right = min(right, _MAX);
        
        while(left <= right)
        {
            int mid = (left+right)*1.0/2;
            if(mid*mid<=x)
            {
                ans = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return ans;
    }
};
