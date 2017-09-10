/**
LeetCode-676-Implement Magic Dictionary
10/09/17 09:41:24
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
#include <limits>
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

static unordered_map<int, vector<string>> dicts;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dicts.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i=0; i<dict.size(); i++)
        {
            int len = dict[i].length();
            dicts[len].push_back(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.length();
        if(dicts.find(len) == dicts.end())
            return false;
        
        bool isfind = false;
        for(string s : dicts[len])
        {
            int diff = 0;
            for(int i=0; i<len; i++)
            {
                if(s[i] != word[i])
                {
                    diff++;
                    if(diff > 1)
                        break;
                }
            }
            if(diff == 1)
            {
                isfind = true;
                break;
            }
        }
        return isfind;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
