/*
LeetCode-440-K-th Smallest in Lexicographical Order
03/12/16 12:47:00
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

const int MAX = 0x3f3f3f3f;

class Solution {
private:
    int getSteps(long long n1, long long n2, long long n)
    {
        int steps = 0;
        while(n1 <= n)
        {
            steps += min(n2, n+1) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k -= 1;
        while(k>0)
        {
            int steps = getSteps(cur, cur+1, n);
            if(steps<=k)
            {
                cur = cur+1;
                k -= steps;
            }
            else
            {
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }
};
