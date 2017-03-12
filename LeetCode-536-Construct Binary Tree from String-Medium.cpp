/*
LeetCode-536-Construct Binary Tree from String
12/03/17 10:58:40
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int NONUMBER = INT_MIN;
class Solution {
private:
    int pick(string& s, int pos)
    {
        int val = 0;
        int flag = 1;
        if(s[pos]=='-')
        {
            flag = -1;
            ++pos;
        }
        while(s[pos]>='0' && s[pos]<='9')
        {
            val *= 10;
            val += s[pos]-'0';
            ++pos;
        }
        val *= flag;
        
        return val;
    }
    TreeNode* trace(string& s, int& pos)
    {
        if(pos>=s.length())
            return NULL;
        int t = pick(s, pos);
        TreeNode* cur = new TreeNode(t);
        
        bool hasleft = false;
        bool hasright = false;
        while(s[pos]!='(' && s[pos]!=')')
            ++pos;
        if(s[pos]=='(')
            hasleft = true;
        if(hasleft)
        {
            ++pos;
            cur->left = trace(s, pos);
            if(s[pos]=='(')
                hasright = true;
            if(hasright)
            {
                ++pos;
                cur->right = trace(s, pos);
            }
        }
        pos += 1;
        return cur;
    }
public:
    TreeNode* str2tree(string s) {
        int n = s.length();
        int pos = 0;
        TreeNode *ret = trace(s, pos);
        
        return ret;
    }
};
