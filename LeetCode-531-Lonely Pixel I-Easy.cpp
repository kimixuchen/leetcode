/*
LeetCode-531-Lonely Pixel I
05/03/17 10:48:06
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <priority_queue>
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
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        if(n==0)
            return 0;
        int m = picture[0].size();
        
        vector<int> rowB(n);
        vector<int> colB(m);
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(picture[i][j]=='B')
                {
                    rowB[i]++;
                    colB[j]++;
                }
            }
        }
        
        int ret = 0;
        for(int i=0; i<n; ++i)
        {
            if(rowB[i]==1)
            {
                for(int j=0; j<m; ++j)
                {
                    if(picture[i][j]=='B')
                    {
                        if(colB[j]==1)
                        {
                            ++ret;
                        }
                        break;
                    }
                }
            }
        }
        
        return ret;
        
    }
};
