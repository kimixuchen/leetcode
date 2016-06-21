/**
LeetCode-50-Pow(x,n)
21/06/16 08:32:31
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        double _min = 0.000001;
        double _max = 1000000;
        double DBL_MAX = 1E37;
        double PRE = 1E-11;
        if(abs(abs(x)-1) < PRE)
        {
            if(x<0)
                ans = n%2==0 ? 1 : -1;
        }
        else if(n==0)
            ans = 1;
        else
        {
            if(n<0)
            {
                x = 1/x;
                n = -n;
            }
            while(n>0)
            {
                if(n%2==1)
                    ans*=x;
                x*=x;
                n/=2;
                if(abs(x) < _min)
                    break;
                if(abs(x) > DBL_MAX)
                    break;
            }
        }
        return ans;
    }
};

