/*
LeetCode-372-Super Pow
20/11/16 09:49:52
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
    const int MOD = 1337;
    
    int f(int a, vector<int>& b)
    {
        long long ret=1;
        int n = b.size();
        if(n==1)
        {
            for(int i=0; i<b[0]; ++i)
            {
                ret *= a;
                ret %= MOD;
            }
        }
        else
        {
            vector<int> tail(1, b[n-1]);
            b.pop_back();
            long long tmp = f(a, b);
            ret = tmp;
            for(int i=1; i<10; ++i)
            {
                ret *= tmp;
                ret %= MOD;
            }
            ret *= f(a, tail);
            ret %= MOD;
        }
        return ret;
    
    }
public:
    int superPow(int a, vector<int>& b) {
        return f(a, b);
    }
};
