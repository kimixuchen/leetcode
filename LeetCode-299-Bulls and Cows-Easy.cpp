/*
LeetCode-299-Bulls and Cows
22/10/16 12:29:24
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int m[10];
        memset(m, 0, sizeof(m));
        
        for(int i=0; i<secret.length(); ++i)
        {
            if(secret[i]==guess[i])
                ++bulls;
            else
            {
                if(m[guess[i]-'0']++ < 0)
                    ++cows;
                if(m[secret[i]-'0']-- > 0)
                    ++cows;
            }
        }
        
        
        return to_string(bulls)+'A'+to_string(cows)+'B';
        
    }
};
