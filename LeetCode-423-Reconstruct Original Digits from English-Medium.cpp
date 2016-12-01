/*
LeetCode-423-Reconstruct Original Digits from English
01/12/16 10:49:10
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

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    string originalDigits(string s) {
        string words[10] = {"zero", "one", "two", "three", "four", "five", "six",
            "seven", "eight", "nine"};
        int orders[10] = {0, 2, 6, 4, 7, 5, 1, 3, 8, 9};
        int letters[26] = {0};
        int nums[10] = {0};
        
        for(char c : s)
        {
            letters[c-'a']++;
        }
        
        for(int i=0; i<10; ++i)
        {
            int order = orders[i];
            string word = words[order];
            int _mincount = INT_MAX;
            for(char c : word)
            {
                _mincount = min(_mincount, letters[c-'a']);
            }
            nums[order] = _mincount;
            for(char c : word)
            {
                letters[c-'a'] -= _mincount;
            }
        }
        
        string ret;
        for(int i=0; i<10; ++i)
        {
            for(int j=0; j<nums[i]; ++j)
                ret += to_string(i);
        }
        return ret;
        
    }
};
