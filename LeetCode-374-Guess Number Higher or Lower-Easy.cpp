/*
LeetCode-374-Guess Number Higher or Lower
03/11/16 10:47:55
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

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while(lo<hi)
        {
            int mid = lo + (hi-lo)/2;
            switch(guess(mid))
            {
                case -1:
                    hi = mid-1;
                    break;
                case 1:
                    lo = mid+1;
                    break;
                default:
                    return mid;
            }
        }
        return lo;
        
    }
};
