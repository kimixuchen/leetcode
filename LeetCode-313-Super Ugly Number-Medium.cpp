/*
LeetCode-313-Super Ugly Number
26/10/16 09:08:37
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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> poss(primes.size(), 0);
        vector<int> nums;
        nums.push_back(1);
        int counter = 1;
        while(counter<n)
        {
            ++counter;
            int m = INT_MAX;
            for(int i=0; i<primes.size(); ++i)
            {
                m = min(m, primes[i]*nums[poss[i]]);
            }
            for(int i=0; i<primes.size(); ++i)
            {
                if(m==primes[i]*nums[poss[i]])
                    poss[i]++;
            }
            
            nums.push_back(m);
        }
        
        return nums.back();
    }
};
