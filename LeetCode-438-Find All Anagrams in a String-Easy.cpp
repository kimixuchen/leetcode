/*
LeetCode-438-Find All Anagrams in a String
23/10/16 10:29:17
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(128, 0);
        int counter=0;
        int begin=0, end=0;
        vector<int> sum;
        for(int i=0; i<p.length(); ++i)
            m[p[i]-'a']++;
        
        int fele;
        while(end < s.size())
        {
            fele = -1;
            if(m[s[end++]-'a']-- > 0)
            {
                counter++;
            }
            else
                fele = s[end-1];
            
            if(counter==p.length() && fele==-1)
                sum.push_back(begin);
            
            if(fele > -1)
            {
                while(begin<end)
                {
                    m[s[begin]-'a']++;
                    if(s[begin]!=fele)
                    {
                        ++begin;
                        --counter;
                    }
                    else
                    {
                        ++begin;
                        break;
                    }
                }
            }
        }
        
        return sum;
    }
};
