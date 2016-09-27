/**
LeetCode-211-Add and Search Word-Data structure design
27/09/16 09:35:44
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

class TrieNode
{
public:
    bool isword;
    TrieNode* next[26];
    TrieNode()
    {
        isword = false;
        memset(next, 0, sizeof(next));
    }
};

class WordDictionary {
private:
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *cur = root;
        for(int i=0; i<word.size(); ++i)
        {
            if(cur->next[word[i]-'a'] != NULL)
                cur = cur->next[word[i]-'a'];
            else
            {
                TrieNode *tmp = new TrieNode();
                cur->next[word[i]-'a'] = tmp;
                cur = tmp;
            }
        }
        cur->isword = true;
        
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int n;
        queue<TrieNode*> q;
        TrieNode *cur;
        q.push(root);
        for(int i=0; i<word.length(); ++i)
        {
            n = q.size();
            for(int j=0; j<n; ++j)
            {
                cur = q.front();
                q.pop();
                if(word[i]=='.')
                {
                    for(int k=0; k<26; ++k)
                        if(cur->next[k] != NULL)
                            q.push(cur->next[k]);
                }
                else
                {
                    if(cur->next[word[i]-'a'] != NULL)
                        q.push(cur->next[word[i]-'a']);
                }
            }
        }
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            if(cur->isword == true)
                return true;
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
