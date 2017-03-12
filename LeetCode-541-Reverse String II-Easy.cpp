/*
LeetCode-541-Reverse String II
12/03/17 10:31:12
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
public:
    string reverseStr(string s, int k) {
        if(k<=0)
            return s;
        
        int n = s.length();
        int pos = 0;
        while(pos < n)
        {
            int next = min(pos+k, n);
            reverse(s.begin()+pos, s.begin()+next);
            pos += k*2;
        }
        
        return s;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseStr("abcdefg", 18)<<endl;
    
    return 0;

}
