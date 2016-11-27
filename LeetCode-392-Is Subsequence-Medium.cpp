/*
LeetCode-392-Is Subsequence
27/11/16 09:00:09
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
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
private:
    int bsearch(int prepos, vector<int> &letterPoss)
    {
        int l = 0;
        int r = letterPoss.size();
        
        if(r==0)
            return -1;
        
        while(l < r)
        {
            int mid = l+(r-l)/2;
            if(letterPoss[mid]<=prepos)
            {
                l = mid+1;
            }
            else
                r = mid;
        }
        if(l<letterPoss.size())
            return letterPoss[l];
        else
            return -1;
    }
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> letters(26, vector<int>());
        
        for(int i=0; i<t.length(); ++i)
        {
            letters[t[i]-'a'].push_back(i);
        }
        
        bool isSe = true;
        int prepos = -1;
        for(int i=0; i<s.length(); ++i)
        {
            int pos = bsearch(prepos, letters[s[i]-'a']);
            //printf("prepos=%d pos=%d\n", prepos, pos);
            if(pos>-1)
            {
                prepos = pos;
            }
            else
            {
                isSe = false;
                break;
            }
        }
        return isSe;
        
    }
};
