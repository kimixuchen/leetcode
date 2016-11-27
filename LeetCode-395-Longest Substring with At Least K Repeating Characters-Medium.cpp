/*
LeetCode-395-Longest Substring with At Least K Repeating Characters
27/11/16 12:33:06
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
private:
    int search(string &s, int start, int end, int k)
    {
        if(end<start)
            return 0;
        
        
        if(end-start+1 < k)
            return 0;
        
        int letters[26];
        memset(letters, 0, sizeof(letters));
        for(int i=start; i<=end; ++i)
        {
            letters[s[i]-'a']++;
        }
        
        for(int i=0; i<26; ++i)
        {
            if(letters[i]==0)
                continue;
            
            if(letters[i]<k)
            {
                for(int j=start; j<=end; ++j)
                {
                    if(s[j]==i+'a')
                    {
                        int len1 = search(s, start, j-1, k);
                        int len2 = search(s, j+1, end, k);
                        return max(len1, len2);
                    }
                }
            }
        }
        
        return end-start+1;
    
    }
public:
    int longestSubstring(string s, int k) {
        int len = s.length();
        
        return search(s, 0, len-1, k);
        
    }
};


