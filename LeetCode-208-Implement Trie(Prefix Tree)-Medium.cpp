/**
LeetCode-208-Implement Trie(Prefix Tree)
26/09/16 10:36:30
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

class TrieNode {
public:
    // Initialize your data structure here.
    int count;
    TrieNode* next[26];
    
    TrieNode() {
        count = 0;
        for(int i=0; i<26; ++i)
            next[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        int pos;
        for(int i=0; i<word.length(); ++i)
        {
            pos = word[i]-'a';
            ++(cur->count);
            if(cur->next[pos] != NULL)
            {
                cur = cur->next[pos];
            }
            else
            {
                TrieNode *tmp = new TrieNode();
                cur->next[pos] = tmp;
                cur = tmp;
            }
        }
        ++(cur->count);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        int pos;
        for(int i=0; i<word.length(); ++i)
        {
            pos = word[i]-'a';
            if(cur->next[pos] == NULL)
                return false;
            else
                cur = cur->next[pos];
        }
        int sum=0;
        for(int i=0; i<26; ++i)
        {
            if(cur->next[i] != NULL)
                sum += cur->next[i]->count;
        }
        
        return (cur->count) > sum;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        int pos;
        for(int i=0; i<prefix.length(); ++i)
        {
            pos = prefix[i]-'a';
            if(cur->next[pos] == NULL)
                return false;
            else
                cur = cur->next[pos];
        }
        
        return true;
        
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
    Trie trie;
    trie.insert("ab");
    cout<<trie.search("a")<<endl;
    return 0;
}
