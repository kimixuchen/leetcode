/**
LeetCode-166-Fraction to Recurring Decimal
20/09/16 09:26:01
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
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        
        string ret;
        int64_t n = numerator, d = denominator;
        int64_t intPart, fracPart;
        if(n>0 ^ d>0)
            ret += "-";
        n = abs(n); d = abs(d);
        intPart = n/d;
        fracPart = n%d;
        ret += to_string(intPart);
        if(fracPart == 0)
            return ret;
        
        ret += '.';
        
        int64_t r = fracPart;
        string res;
        unordered_map<int, int> m;
        while(r != 0)
        {
            if(m.find(r) != m.end())
            {
                res.insert(m[r], "(");
                res += ')';
                break;
            }
            
            m[r] = res.size();
            r *= 10;
            if(r<d)
            {
                res += '0';
            }
            else
            {
                res += '0' + r/d;
                r = r%d;
            }
        }
        
        ret += res;
        return ret;
        
    }
};

int main()
{
    Solution s;
    cout<<s.fractionToDecimal(-1, INT_MIN)<<endl;

    return 0;
}
