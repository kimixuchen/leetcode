/*
LeetCode-378-Kth Smallest Element in a Sorted Matrix
21/11/16 20:14:17
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

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];
        
        while(lo < hi)
        {
            int mid = lo + (hi-lo)/2;
            int sum = 0;
            for(int i=0; i<n; ++i)
            {
                int j = n-1;
                while(j>=0 && matrix[i][j]>mid)
                    --j;
                sum += (j+1);
            }
            if(sum < k)
                lo = mid+1;
            else
                hi = mid;
        }
        return lo;
        
    }
};
