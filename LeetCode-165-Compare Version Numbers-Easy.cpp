/**
LeetCode-165-Compare Version Numbers
20/09/16 08:50:28
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    int compareVersion(string version1, string version2) {
        int pos1, pos2;
        pos1 = pos2 = 0;
        int i, j;
        i = j = 0;
        while(i<version1.length() && j<version2.length())
        {
            int v1, v2;
            while(i<version1.length() && version1[i]!='.')
                ++i;
            v1 = atoi(version1.substr(pos1, i).c_str());
            pos1 = ++i;
            
            while(j<version2.length() && version2[j]!='.')
                ++j;
            v2 = atoi(version2.substr(pos2, j).c_str());
            pos2 = ++j;
            
            if(v1<v2)
                return -1;
            else if(v1>v2)
                return 1;
        }
        
        if(i>=version1.length() && j>=version2.length())
            return 0;
        
        if(i>=version1.length())
        {
            for( ; j<version2.length(); ++j)
                if(version2[j]!='0' && version2[j]!='.')
                    return -1;
            
            return 0;
        }
        else
        {
            for( ; i<version1.length(); ++i)
                if(version1[i]!='0' && version1[i]!='.')
                    return 1;
            
            return 0;
        }
    }
};
