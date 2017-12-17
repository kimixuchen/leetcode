/**
LeetCode-748-Shortest Completing Word
17/12/17 10:54:25
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
#include <limits>
#include "limits.h"
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        char letters[26];
        char cmpLetters[26];
        int minLen = INT_MAX;
        int minPos = -1;
        memset(letters, 0, sizeof(letters));
        
        for(char c : licensePlate)
        {
            if(c>='A' && c<='Z')
            {
                c += 'a'-'A';
            }
            if(c >= 'a' && c<= 'z')
            {
                letters[c-'a']++;
            }
        }
        
        for(int i=0; i<words.size(); i++)
        {
            memset(cmpLetters, 0, sizeof(cmpLetters));
            for(char c : words[i])
            {
                cmpLetters[c-'a']++;
            }
            bool cover = true;
            for(int j=0; j<26; j++)
            {
                if(cmpLetters[j]<letters[j])
                {
                    cover = false;
                    break;
                }
            }
            if(cover)
            {
                if(words[i].length() < minLen)
                {
                    minLen = words[i].length();
                    minPos = i;
                }
            }
        }
        return words[minPos];
    }
};
