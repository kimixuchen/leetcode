/*
 * Leetcode 648-Replace Words
 */
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

struct Node {
    char c;
    bool wordend;
    Node *next[26];
    
    Node(char cc, bool cwordend) {
        c = cc;
        wordend = cwordend;
        memset(next, 0, sizeof(next));
    }
};

class Solution {
private:
    Node* buildTree(vector<string> &dict) {
        Node *root = new Node('#', false);
        for(string s : dict) {
            Node *curNode = root;
            for(int i=0; i<s.length(); i++) {
                char c = s[i];
                if(curNode->next[c-'a'] == NULL) {
                    Node *newNode = new Node(c, false);
                    curNode->next[c-'a'] = newNode;
                }
                curNode = curNode->next[c-'a'];
            }
            curNode->wordend = true;
        }
        
        return root;
    }
    
    string search(Node *root, string s) {
        Node *curNode = root;
        string ret;
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(curNode->next[c-'a'] == NULL)
                return s;
            ret.append(1, c);
            curNode = curNode->next[c-'a'];
            if(curNode->wordend)
                break;
        }
        return ret;
    }
public:
    string replaceWords(vector<string>& dict, string sentence) {
        vector<string> words;
        stringstream input(sentence);
        string result;
        while(input>>result)
            words.push_back(result);
            
        int n = words.size();
        
        Node *root = buildTree(dict);
        
        string ret;
        for(int i=0; i<words.size(); i++) {
            string s = words[i];
            string prefix = search(root, s);
            if(i==0)
                ret.append(prefix);
            else{
                ret.append(1, ' ');
                ret.append(prefix);
            }
        }
        
        return ret;
        
    }
};