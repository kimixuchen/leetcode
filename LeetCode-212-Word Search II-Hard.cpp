/**
LeetCode-212-Word Search II
28/09/16 08:56:10
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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

class TireNode{
public:
    TireNode *next[26];
    string word;
    TireNode()
    {
        word = "";
        memset(next, 0, sizeof(next));
    }
};

class Solution {
public:
    void build(TireNode *root, vector<string>& words)
    {
        for(int i=0; i<words.size(); ++i)
        {
            TireNode *cur = root;
            for(int j=0; j<words[i].length(); ++j)
            {
                if(cur->next[words[i][j]-'a'] != NULL)
                    cur = cur->next[words[i][j]-'a'];
                else
                {
                    cur->next[words[i][j]-'a'] = new TireNode();
                    cur = cur->next[words[i][j]-'a'];
                }
            }
            cur->word = words[i];
        }
    }
    
    void search(vector<vector<char>>& board, int i, int j, TireNode *root, 
            vector<string> &ret)
    {
        if(board[i][j] == '#')
            return;
        
        TireNode *cur = root;
        TireNode *next = root->next[board[i][j]-'a'];
        if(next != NULL)
        {
            if(next->word != "")
            {
                ret.push_back(next->word);
                next->word = "";
            }
            char pre = board[i][j];
            board[i][j] = '#';
            if(i>0)
                search(board, i-1, j, next, ret);
            if(i<board.size()-1)
                search(board, i+1, j, next, ret);
            if(j>0)
                search(board, i, j-1, next, ret);
            if(j<board[0].size()-1)
                search(board, i, j+1, next, ret);
            board[i][j] = pre;
        }
        return;
    
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TireNode *root = new TireNode();
        build(root, words);
        vector<string> ret;
        
        for(int i=0; i<board.size(); ++i)
            for(int j=0; j<board[0].size(); ++j)
                search(board, i, j, root, ret);
        
        return ret;
        
    }
};
