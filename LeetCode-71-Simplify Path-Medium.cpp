/**
LeetCode-71-Simplify Path
10/07/16 08:44:09
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
    string simplifyPath(string path) {
        stack<string> pathStack;
        int pos = 0;
        int len = path.length();
        string folder;
        while(pos < len)
        {
            char c = path[pos];
            switch(c)
            {
                case '/':
                    if(folder == "." || folder == "")
                    {
                    }
                    else if(folder == "..")
                    {
                        if(!pathStack.empty())
                        {
                            pathStack.pop();
                        }
                    }
                    else
                    {
                        pathStack.push(folder);
                    }
                    folder = "";
                    break;
                
                case '.':
                    folder += c;
                    break;
                
                default:
                    folder += c;
            }
            ++pos;
        }
        if(folder == "." || folder == "")
        {
        }
        else if(folder == "..")
        {
            if(!pathStack.empty())
            {
                pathStack.pop();
            }
        }
        else
        {
            pathStack.push(folder);
        }
        
        string ret;
        while(!pathStack.empty())
        {
            ret = '/' + pathStack.top() + ret;
            pathStack.pop();
        }
        if(ret == "")
            ret = "/";
        return ret;
    }
};
