/**
LeetCode-66-Plus One
02/07/16 10:30:16
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
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while( i>=0 )
        {
            digits[i] = ( ++digits[i] % 10 );
            if( 0!=digits[i] )
            {
                break;
            }
            --i;
        }
        if(i<0)
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
