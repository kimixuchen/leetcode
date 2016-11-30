/*
LeetCode-413-Arithmetic Slices
30/11/16 09:47:36
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
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()==0)
            return 0;
        
        vector<int> difflen(A.size(), 0);
        
        int counter = 0;
        difflen[0] = 0;
        difflen[1] = 1;
        for(int i=2; i<A.size(); ++i)
        {
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
            {
                counter += difflen[i-1];
                difflen[i] = difflen[i-1]+1;
            }
            else
            {
                difflen[i] = 1;
            }
        }
        
        return counter;
    }
};
