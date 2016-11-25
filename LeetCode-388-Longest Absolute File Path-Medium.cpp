/*
LeetCode-388-Longest Absolute File Path
25/11/16 09:03:35
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
    int deleteTab(string s, int &pos)
    {
        int counter = 0;
        while(pos+1 < s.length())
        {
            if(s[pos]=='\t')
            {
                ++counter;
                pos++;
            }
            else
                break;
        }
        
        return counter;
    }
    
    bool isFile(string s, int pos)
    {
        bool hasDot = false;
        while(pos < s.length())
        {
            if(s[pos]=='.')
                hasDot = true;
            if(s[pos]=='\n')
                break;
            ++pos;
        }
        
        return hasDot;
    
    }
    
    int deleteFile(string s, int &pos)
    {
        int pre = pos;
        while(pos < s.length() && s[pos]!='\n')
            ++pos;
        int ret = pos-pre;
        
        pos++;   //skip '\n'
        
        return ret;
    
    }
    
    bool isDir(string s, int pos)
    {
        return !isFile(s, pos);
    }
    
    int deleteDir(string s, int &pos)
    {
        return deleteFile(s, pos);
    }
    
    int getPathlen(vector<int> &path, int filelen)
    {
        int len = filelen;
        for(int i : path)
            len += i+1;
        
        return len;
    
    }
    
public:
    int lengthLongestPath(string input) {
        vector<int> path;
        int pos = 0;
        int depth = 0;
        
        int _max = 0;
        while(pos < input.length())
        {
            int sum = 0;
            int d = deleteTab(input, pos);
            while(path.size() > d)
                path.pop_back();
            
            if(isFile(input, pos))
            {
                int filelen = deleteFile(input, pos);
                _max = max(_max, getPathlen(path, filelen));
            }
            else if(isDir(input, pos))
            {
                int dirlen = deleteDir(input, pos);
                path.push_back(dirlen);
            }
        }
        
        return _max;
    }
};
