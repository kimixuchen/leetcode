/*
LeetCode-537-Complex Number Multiplication
06/04/17 10:15:47
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
private:
    pair<int, int> parse(string s)
    {
        int a=0, b=0;
        int flag = 1;
        int pos = 0;
        int n = s.length();
        while(pos<n)
        {
            if(s[pos]=='-')
                flag = -1;
            else if(s[pos]=='+')
            {
                ++pos;
                break;
            }
            else
            {
                a *= 10;
                a += s[pos]-'0';
            }
            ++pos;
        }
        a *= flag;
        flag = 1;
        while(pos<n)
        {
            if(s[pos]=='-')
                flag = -1;
            else if(s[pos]=='i')
            {
                ++pos;
                break;
            }
            else
            {
                b *= 10;
                b += s[pos]-'0';
            }
            ++pos;
        }
        b *= flag;
        
        return make_pair(a, b);
    }

public:
    string complexNumberMultiply(string a, string b) {
        int a1, b1, a2, b2;
        auto p1 = parse(a);
        auto p2 = parse(b);
        
        a1 = p1.first;
        b1 = p1.second;
        a2 = p2.first;
        b2 = p2.second;
        
        int ra, rb;
        
        ra = a1*a2 - b1*b2;
        rb = a1*b2 + a2*b1;
        
        return to_string(ra)+"+"+to_string(rb)+"i";
    }
};
