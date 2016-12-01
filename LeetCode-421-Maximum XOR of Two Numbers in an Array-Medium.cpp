/*
LeetCode-421-Maximum XOR of Two Numbers in an Array
01/12/16 10:05:27
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
    int findMaximumXOR(vector<int>& nums) {
        int _max=0, mask=0;
        for(int i=31; i>=0; --i)
        {
            mask = mask | 1<<i;
            unordered_set<int> uset;
            for(int a : nums)
                uset.insert(a&mask);
            
            int tmp = _max | 1<<i;
            for(int a : uset)
            {
                // if a^b=c then a^c=b
                if(uset.find(tmp^a)!=uset.end())
                {
                    _max = tmp;
                    break;
                }
            }
        }
        return _max;
        
    }
};
