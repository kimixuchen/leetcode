/**
LeetCode-233-Number of Digit One
12/10/16 08:36:45
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
    int countDigitOne(int n) {
        if(n<0)
            return 0;
        
        int pre = 0;
        int len = 0;
        int sum = 0;
        int m = n;
        while(m>0) {m/=10; ++len;}
        
        int rest, unit, num;
        for(int i=0; i<len; ++i)
        {
            unit = pow(10, len-i-1);
            num = (n/unit)%10;
            rest = n%unit;
            
            if(num==0)
            {
                sum += pre*unit;
            }
            else if(num==1)
            {
                sum += pre*unit+rest+1;
            }
            else
            {
                sum += (pre+1)*unit;
            }
            pre *= 10;
            pre += num;
        }
        
        return sum;
        
    }
};
