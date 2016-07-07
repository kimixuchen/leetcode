/**
LeetCode-68-Text Justification
07/07/16 10:39:58
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int count = words.size();
        vector<string> ret;
        if(count == 0)
        {
            string s(maxWidth, ' ');
            ret.push_back(s);
            return ret;
        }
        
        int pos = 0;
        while(pos < count)
        {
            int pre = pos;
            string s;
            int len = 0;
            len += words[pos].length();
            ++pos;
            while((pos < count) && (words[pos].length()+1 + len <= maxWidth))
            {
                len += words[pos].length()+1;
                ++pos;
            }
            int spaceNum = pos-1-pre;
            int totalSpace = maxWidth-len+spaceNum;
            int left, baseNum;
            if(pos < count)
            {
                if(spaceNum > 0)
                {
                    left = totalSpace%spaceNum;
                    baseNum = totalSpace/spaceNum;
                }
                else
                {
                    left = 0;
                    baseNum = maxWidth-words[pre].length();
                }
                string base(baseNum, ' ');
                
                for(int i=pre; i<pos; ++i)
                {
                    if(i-pre > 0)
                    {
                        if(i-pre <= left)
                            s += base+' ';
                        else
                            s += base;
                    }
                    s += words[i];
                }
                if(spaceNum==0)
                {
                    s += base;
                }
            }
            else
            {
                s += words[pre];
                len = 0;
                len += words[pre].length();
                for(int i=pre+1; i<count; ++i)
                {
                    s += " ";
                    s += words[i];
                    len += words[i].length() + 1;
                }    
                string base(maxWidth-len, ' ');
                s += base;
            }
            
            ret.push_back(s);
        }
        
        return ret;
        
    }
};
