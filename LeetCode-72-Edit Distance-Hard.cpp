/**
LeetCode-72-Edit Distance
11/07/16 19:52:50
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
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<int> tmp(len2+1, 0);
        vector<vector<int>> dis(len1+1, tmp);
        
        for(int j=0; j<len2+1; ++j)
            dis[0][j] = j;
        for(int i=0; i<len1+1; ++i)
            dis[i][0] = i;
        
        for(int i=0; i<len1; ++i)
        {
            for(int j=0; j<len2; ++j)
            {
                int cost = 0;
                if(word1[i] != word2[j])
                    cost = 1;
                
                dis[i+1][j+1] = dis[i][j+1] + 1;
                dis[i+1][j+1] = min(dis[i+1][j+1], dis[i+1][j]+1);
                dis[i+1][j+1] = min(dis[i+1][j+1], dis[i][j]+cost);
            }
        }
        return dis[len1][len2];
    }
};
