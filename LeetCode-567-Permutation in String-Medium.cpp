/*
LeetCode-567-Permutation in String
12/05/17 09:06:08
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
    bool allZero(vector<int> &chars)
    {
        for(int i : chars)
        {
            if(i!=0)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        if(n==0)
            return true;
        if(s1.length()>s2.length())
            return false;
        
        vector<int> chars(128, 0);
        for(int i=0; i<n; ++i)
        {
            chars[s1[i]]++;
            chars[s2[i]]--;
        }
        if(allZero(chars))
            return true;
        
        for(int i=n; i<s2.length(); ++i)
        {
            chars[s2[i-n]]++;
            chars[s2[i]]--;
            if(allZero(chars))
                return true;
        }
        return false;
    }
};
