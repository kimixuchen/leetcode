/*
LeetCode-412-FIzz Buzz
30/11/16 09:42:25
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
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        
        for(int i=1; i<=n; ++i)
        {
            if(i%3==0 && i%5==0)
                ret.push_back("FizzBuzz");
            else if(i%3==0)
                ret.push_back("Fizz");
            else if(i%5==0)
                ret.push_back("Buzz");
            else
                ret.push_back(to_string(i));
        }
        
        return ret;
        
    }
};
