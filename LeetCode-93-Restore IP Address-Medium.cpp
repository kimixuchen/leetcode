/**
LeetCode-93-Restore IP Address
18/07/16 10:22:40
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    void addAnswer(vector<string> &ret, vector<int> &ans)
    {
        string s;
        for(int i=0; i<ans.size()-1; ++i)
        {
            s += to_string(ans[i]);
            s += '.';
        }
        s += to_string(ans.back());
        ret.push_back(s);
        
        return;
    }
    
    void dfs(vector<string> &ret, string s, int begin, vector<int> &ans)
    {
        if(begin == s.length())
        {
            if(ans.size()==4)
            {
                addAnswer(ret, ans);
            }
            return;
        }
        if(ans.size()>4)
            return;
        
        int num = 0;
        for(int i=begin; i<s.length(); ++i)
        {
            num*=10;
            num += s[i]-'0';
            if(num > 255 || (i>begin && s[begin]=='0'))
                break;
            
            ans.push_back(num);
            dfs(ret, s, i+1, ans);
            ans.pop_back();
        }
        return;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<int> ans; 
        if(s.length() == 0)
            return ret;
        
        dfs(ret, s, 0, ans);
        
        return ret;
    }
};
