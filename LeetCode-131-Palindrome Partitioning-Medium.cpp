/**
LeetCode-131-Palindrome Partitioning
07/09/16 10:24:38
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
    bool isPalindrome(string& s, int pos)
    {
        int left = 0, right = pos;
        while(left <= right)
        {
            if(s[left] != s[right])
                break;
            ++left;
            --right;
        }
        if(left > right)
            return true;
        else
            return false;
    }
    
    void dfs(vector<vector<string>> &ret, vector<string>& cur, string s)
    {
        if(s=="")
        {
            ret.push_back(cur);
            return;
        }
        for(int i=0; i<s.length(); ++i)
        {
            if(isPalindrome(s, i))
            {
                cur.push_back(s.substr(0, i+1));
                dfs(ret, cur, s.substr(i+1));
                cur.pop_back();
            }
        }
        return;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> cur;
        dfs(ret, cur, s);
        
        return ret;
    }
};
