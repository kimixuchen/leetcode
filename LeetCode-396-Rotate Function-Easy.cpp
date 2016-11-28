/*
LeetCode-396-Rotate Function
28/11/16 08:48:24
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
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int cur = 0;
        int n = A.size();
        for(int i=0; i<n; ++i)
        {
            sum += A[i];
            cur += i*A[i];
        }
        
        int _max = cur;
        
        for(int i=n-1; i>0; --i)
        {
            cur = cur+sum-A[i]*n;
            _max = max(_max, cur);
        }
        
        return _max;
        
    }
};
