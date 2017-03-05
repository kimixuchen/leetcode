/*
LeetCode-531-Lonely Pixel II
05/03/17 11:07:06
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
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n = picture.size();
        if(n==0)
            return 0;
        int m = picture[0].size();
        
        vector<int> rowB(n);
        vector<int> colB(m);
        vector<string> rowid(n);
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(picture[i][j]=='B')
                {
                    rowB[i]++;
                    colB[j]++;
                    rowid[i] += "#"+to_string(j);
                }
            }
        }
        
        int ret = 0;
        for(int i=0; i<n; ++i)
        {
            if(rowB[i]==N)
            {
                for(int j=0; j<m; ++j)
                {
                    if(picture[i][j]=='B')
                    {
                        if(colB[j]==N)
                        {
                            bool flag = true;
                            for(int r=0; r<n; ++r)
                            {
                                if(picture[r][j]=='B' && rowid[r]!=rowid[i])
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if(flag)
                                ++ret;
                        }
                    }
                }
            }
        }
        
        return ret;
        
    }
};
