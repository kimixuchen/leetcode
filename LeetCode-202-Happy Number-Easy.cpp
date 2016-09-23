/**
LeetCode-202-Happy Number
23/09/16 09:51:50
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1)
        {
            if(s.find(n)!=s.end())
                return false;
            s.insert(n);
            
            int sum=0;
            while(n>0)
            {
                sum += (n%10)*(n%10);
                n/=10;
            }
            n = sum;
        }
        
        return true;
        
    }
};
