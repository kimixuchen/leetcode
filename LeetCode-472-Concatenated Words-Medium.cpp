/*
LeetCode-472-Concatenated Words
24/12/16 16:29:10
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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        unordered_map<string, bool> map;
        for(string s : words)
            map[s] = true;
        
        for(string s : words)
        {
            if(search(map, s, true))
                ret.push_back(s);
        }
        
        return ret;
    }
    
    bool search(unordered_map<string, bool> &map, string s, bool isOriginal)
    {
        if(map.find(s)!=map.end() && !isOriginal)
        {
            return map[s];
        }
        
        bool flag = false;
        for(int i=1; i<s.length(); ++i)
        {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, s.length()-i);
            if(map.find(s1)!=map.end() && map[s1])
            {
                flag = search(map, s2, false);
            }
            if(flag)
                break;
        }
        
        if(map.find(s)==map.end())
            map[s] = flag;
        return flag;
    }
};
