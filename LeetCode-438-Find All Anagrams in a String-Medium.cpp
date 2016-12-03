/*
LeetCode-438-Find All Anagrams in a String
03/12/16 09:34:54
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
    bool match(vector<int> &letters)
    {
        for(int i=0; i<letters.size(); ++i)
            if(letters[i]>0 || letters[i]<0)
                return false;
        
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> letters(26, 0);
        vector<int> ret;
        
        if(p.length() > s.length())
            return ret;
        
        for(char c : p)
            letters[c-'a']++;
        
        for(int i=0; i<p.length(); ++i)
            letters[s[i]-'a']--;
        
        int start = 0, end = p.length()-1;
        while(end < s.length())
        {
            if(match(letters))
            {
                ret.push_back(start);
            }
            letters[s[start]-'a']++;
            ++start;
            ++end;
            if(end < s.length())
                letters[s[end]-'a']--;
        }
        
        return ret;
    }
};
