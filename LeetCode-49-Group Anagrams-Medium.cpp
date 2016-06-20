/**
LeetCode-49-Group Anagrams
20/06/16 20:42:57
**/
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> dic;
        for(vector<string>::iterator it = strs.begin(); it!=strs.end(); ++it)
        {
            string s = *it;
            sort(s.begin(), s.end());
            dic.push_back(make_pair(s, *it));
        }
        sort(dic.begin(), dic.end(), [this](const pair<string, string>&a, 
                    const pair<string, string>&b)
                {
                    return a.first < b.first;
                });
        vector<vector<string>> ret;
        vector<string> tmp;
        string key = "WERRTTYUUU";
        for(vector<pair<string,string>>::iterator it = dic.begin(); it!=dic.end(); ++it)
        {
            if(key=="WERRTTYUUU" || it->first!=key)
            {
                key = it->first;
                if(!tmp.empty())
                    ret.push_back(tmp);
                tmp.clear();
            }
                tmp.push_back(it->second);
        }
        ret.push_back(tmp);
        return ret;
    }
};

