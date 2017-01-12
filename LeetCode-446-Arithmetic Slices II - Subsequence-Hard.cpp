/*
LeetCode-446-Arithmetic Slices II - Subsequence
12/01/17 10:22:25
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

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n==0)
            return 0;
        
        vector<unordered_map<int, int>> dpTn(n);
        
        int cnt = 0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                long long gap = (long long)A[i]-A[j];
                if(gap < INT_MIN || gap > INT_MAX)
                    continue;
                if(dpTn[j].find(gap)!=dpTn[j].end())
                {
                    dpTn[i][gap] += dpTn[j][gap];
                    cnt += dpTn[j][gap];
                }
                
                dpTn[i][gap] += 1;
            }
            /**
            printf("%d\n", A[i]);
            for(auto it = dpT1[i].begin(); it != dpT1[i].end(); ++it)
            {
                printf("%d %d\n", it->first, it->second);
            }
            printf("--------------------\n");
            **/
            
        }
        
        
        
        return cnt;
        
    }
};
