/*
LeetCode-345-Reverse Vowels of a String
04/11/16 10:44:40
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        bool isVowels[128];
        memset(isVowels, 0, sizeof(isVowels));
        isVowels['a'] = isVowels['e'] = isVowels['i']
            = isVowels['o'] = isVowels['u'] = isVowels['A'] = isVowels['E']
            = isVowels['I'] = isVowels['O'] = isVowels['U'] = true;
        
        int i = 0, j = s.length()-1;
        while(i<j)
        {
            while(i<s.length() && !isVowels[s[i]])  ++i;
            while(j>=0 && !isVowels[s[j]])  --j;
            if(i<j)
                swap(s[i], s[j]);
            ++i;
            --j;
        }
        
        return s;
        
    }
};
