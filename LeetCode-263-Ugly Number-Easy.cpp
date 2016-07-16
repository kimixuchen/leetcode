/**
Ugly Number
16/07/16 13:27:33
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    bool isUgly(int num) {
        if(num==0)
            return false;
        while(num%2 == 0)
        {
            num/=2;
        }
        
        while(num%3 == 0)
        {
            num/=3;
        }
        while(num%5 == 0)
        {
            num/=5;
        }
        
        return num==1;
    }
};
