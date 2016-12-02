/*
LeetCode-424-Longest Repeating Character Replacement
02/12/16 08:32:17
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

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int maxCharCount = 0;
        int _max = 0;
        int start = 0;
        int end = 0;
        for(end=0; end<s.length(); ++end)
        {
            counts[s[end]-'A']++;
            if(maxCharCount < counts[s[end]-'A'])
                maxCharCount = counts[s[end]-'A'];
            
            if(end-start-maxCharCount+1>k)
            {
                counts[s[start]-'A']--;
                ++start;
                maxCharCount = 0;
                for(int i=0; i<26; ++i)
                    maxCharCount = max(maxCharCount, counts[i]);
            }
            
            _max = max(_max, end-start+1);
        }
        return _max;
        
    }
};
