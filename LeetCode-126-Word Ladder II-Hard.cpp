/**
LeetCode-126-Word Ladder II
06/09/16 08:45:24
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
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
        vector<vector<string>> paths;
        vector<string> path(1, beginWord);
        if(beginWord == endWord)
        {
            paths.push_back(path);
            return paths;
        }
        
        unordered_set<string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        unordered_map<string, vector<string>> nexts;
        bool words1IsBegin = false;
        if(findLaddersHelper(words1, words2, wordList, nexts, words1IsBegin))
            getPath(beginWord, endWord, nexts, path, paths);
        
        return paths;
    }
    
    bool findLaddersHelper(
            unordered_set<string> &words1,
            unordered_set<string> &words2,
            unordered_set<string> &wordList,
            unordered_map<string, vector<string>> &nexts,
            bool &words1IsBegin)
    {
        words1IsBegin = !words1IsBegin;
        if(words1.empty())
            return false;
        if(words1.size() > words2.size())
            return findLaddersHelper(words2, words1, wordList, nexts, words1IsBegin);
        for(auto it = words1.begin(); it!=words1.end(); ++it)
            wordList.erase(*it);
        unordered_set<string> tmp;
        bool reach = false;
        for(auto it = words1.begin(); it!=words1.end(); ++it)
        {
            string word = *it;
            for(auto ch = word.begin(); ch != word.end(); ++ch)
            {
                char letter = *ch;
                for(*ch = 'a'; *ch <= 'z'; ++(*ch))
                {
                    if(words2.find(word) != words2.end())
                    {
                        reach = true;
                        words1IsBegin ? nexts[*it].push_back(word) : 
                            nexts[word].push_back(*it);
                    }
                    else if(!reach && wordList.find(word) != wordList.end())
                    {
                        tmp.insert(word);
                        words1IsBegin ? nexts[*it].push_back(word) : 
                            nexts[word].push_back(*it);
                    }
                }
                *ch = letter;
            }
        }
        
        return reach || findLaddersHelper(words2, tmp, wordList, nexts, words1IsBegin);
    }
    
    void getPath(
            string beginWord,
            string &endWord,
            unordered_map<string, vector<string>> &nexts,
            vector<string> &path,
            vector<vector<string>> &paths
            )
    {
        if(beginWord == endWord)
            paths.push_back(path);
        else
            for(auto it = nexts[beginWord].begin(); it!=nexts[beginWord].end();
                    ++it)
            {
                path.push_back(*it);
                getPath(*it, endWord, nexts, path, paths);
                path.pop_back();
            }
    }
};
