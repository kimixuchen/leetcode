/*
LeetCode-318-Maximum Product of Word Lengths
26/10/16 09:41:22
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
private:
    bool ok(vector<int> &word1, vector<int> &word2)
    {
        for(int i=0; i<26; ++i)
        {
            if(word1[i]>0 && word2[i]>0)
                return false;
        }
        
        return true;
    }
    
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> swords(words.size(), vector<int>(26, 0));
        for(int i=0; i<words.size(); ++i)
        {
            for(char c : words[i])
            {
                swords[i][c-'a']++;
            }
        }
        
        int mp = 0;
        for(int i=0; i<words.size(); ++i)
        {
            for(int j=i+1; j<words.size(); ++j)
            {
                if(ok(swords[i], swords[j]))
                {
                    if(mp < (words[i].length())*(words[j].length()))
                        mp = (words[i].length())*(words[j].length());
                }
            }
        }
        
        return mp;
        
    }
};
