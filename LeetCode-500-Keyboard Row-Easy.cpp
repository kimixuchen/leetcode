/*
LeetCode-500-Keyboard Row
07/02/17 09:16:57
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

using namespace std;

class Solution {
private:
    int getRow(char c)
    {
        string rows[3] = 
        {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        
        int row = 0;
        for( ; row<3; ++row)
        {
            if(rows[row].find(c)<rows[row].size())
                break;
        }
        return row;
    }
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        for(string s : words)
        {
            if(s=="")
                continue;
            bool isOneRow = true;
            int rownum = -1;
            for(char c : s)
            {
                if(c<'a')
                    c += 'a'-'A';
                
                int row = getRow(c);
                if(rownum==-1)
                    rownum = row;
                else
                {
                    if(rownum != row)
                    {
                        isOneRow = false;
                        break;
                    }
                }
            }
            
            if(isOneRow)
                ret.push_back(s);
        }
        
        return ret;
    }
};

