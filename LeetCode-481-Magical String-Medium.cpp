/*
LeetCode-481-Magical String
08/01/17 10:59:53
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

const int MAX = 100005;

class Solution {
public:
    int magicalString(int n) {
        int nums[MAX];
        memset(nums, 0, sizeof(nums));
        nums[1] = 1;
        nums[2] = 2;
        nums[3] = 2;
        
        int pos1 = 3;
        int pos2 = 2;
        int k = 1;
        while(pos1 < n)
        {
            ++pos2;
            if(nums[pos2]==1)
            {
                ++pos1;
                nums[pos1] = k;
            }
            else
            {
                ++pos1;
                nums[pos1] = k;
                ++pos1;
                nums[pos1] = k;
            }
            k = 3-k;
        }
        int counter = 0;
        for(int i=1; i<=n; ++i)
        {
            printf("%d ", nums[i]);
            if(nums[i]==1)
                ++counter;
        }
        printf("\n");
        
        return counter;
    }
};
