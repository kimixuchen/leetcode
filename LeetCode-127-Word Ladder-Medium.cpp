/**
LeetCode-127-Word Ladder
02/09/16 08:41:25
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
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
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int level = 2;
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        
        while(!head.empty() && !tail.empty())
        {
            if(head.size()<tail.size())
            {
                phead = &head;
                ptail = &tail;
            }
            else
            {
                phead = &tail;
                ptail = &head;
            }
            
            unordered_set<string> tmp;
            for(unordered_set<string>::iterator itr = phead->begin(); itr!=phead->end(); ++itr)
            {
                string word = *itr;
                wordList.erase(word);
                for(int i=0; i<word.length(); ++i)
                {
                    char letter = word[i];
                    for(int k=0; k<26; ++k)
                    {
                        word[i] = k+'a';
                        if(ptail->find(word) != ptail->end())
                        {
                            return level;
                        }
                        if(wordList.find(word) != wordList.end())
                        {
                            tmp.insert(word);
                            wordList.erase(word);
                        }
                    }
                    word[i] = letter;
                }
            }
            swap(*phead, tmp);
            ++level;
        }
        
        return 0;
        
    }
};
