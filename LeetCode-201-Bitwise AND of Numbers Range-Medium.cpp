/**
LeetCode-201-Bitwise AND of Numbers Range
23/09/16 09:08:06
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
    int rangeBitwiseAnd(int m, int n) {
        if(m==n)
            return n;
        int base = 0x40000000;
        while((m&base) == (n&base))
        {
            base |= base>>1;
        }
        
        return m&base;
        
    }
};

int main()
{

    Solution s;
    cout<<s.rangeBitwiseAnd(8, 9)<<endl;
    return 0;
}
