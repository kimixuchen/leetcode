/**
LeetCode-140-Word Break II
12/09/16 08:55:10
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
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
    unordered_map<string, vector<string>> m;
    vector<string> dfs(string s, unordered_set<string>& wordDict)
    {
        if(m.find(s) != m.end())
            return m[s];
        
        vector<string> res;
        if(s=="")
        {
            res.push_back("");
            return res;
        }
        
        for(int i=0; i<s.length(); ++i)
        {
            if(wordDict.find(s.substr(0, i+1)) != wordDict.end())
            {
                auto subvector = dfs(s.substr(i+1), wordDict);
                for(auto itr = subvector.begin(); itr != subvector.end(); ++itr)
                {
                    if(*itr != "")
                        res.push_back(s.substr(0, i+1) + " " + *itr);
                    else
                        res.push_back(s.substr(0, i+1));
                }
            }
        }
        m[s] = res;
        return res;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        return dfs(s, wordDict);
    }
};
