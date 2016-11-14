/*
LeetCode-336-Palindrome Pairs
14/11/16 09:17:32
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
private:
    bool isPalindrome(string &s, int begin, int end)
    {
        int i = begin;
        int j = end;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                ++i;
                --j;
            }
            else
                return false;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        vector<vector<bool>> used(words.size(), vector<bool>(words.size(), false));
        for(int i=0; i<words.size(); ++i)
        {
            string s = words[i];
            reverse(s.begin(), s.end());
            map[s] = i;
        }
        
        vector<vector<int>> ret;
        for(int i=0; i<words.size(); ++i)
        {
            string s = words[i];
            //As prefix
            for(int j=0; j<=s.length(); ++j)
            {
                if(isPalindrome(s, j, s.length()-1) && map.find(s.substr(0, j))!=map.end())
                {
                    int k = map[s.substr(0, j)];
                    if(k==i || used[i][k])
                        continue;
                    vector<int> pair;
                    pair.push_back(i);
                    pair.push_back(k);
                    ret.push_back(pair);
                    used[i][k] = true;
                }
            }
            //As suffix
            for(int j=s.length()-1; j>=-1; --j)
            {
                if(isPalindrome(s, 0, j) && map.find(s.substr(j+1, s.length()-j))!=map.end())
                {
                    int k = map[s.substr(j+1, s.length()-j)];
                    if(k==i || used[k][i])
                        continue;
                    vector<int> pair;
                    pair.push_back(k);
                    pair.push_back(i);
                    ret.push_back(pair);
                    used[k][i] = true;
                }
            }
        }
        return ret;
    }
};
