/**
LeetCode-97-Interleaving String
19/07/16 10:49:33
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
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length())
            return false;
        
        vector<vector<bool>> visited(s1.length()+1, vector<bool>(s2.length()+1, false));
        return search(s1, 0, s2, 0, s3, 0, visited);
    }
    
    bool search(string &s1, int p1, string &s2, int p2, string &s3, int p3, 
            vector<vector<bool>> &visited)
    {
        if(p3 == s3.length())
            return true;
        
        if(visited[p1][p2])
            return false;
        
        if(s1.length()==p1 && s2.substr(p2)==s3.substr(p3))
            return true;
        
        if(s2.length()==p2 && s1.substr(p1) == s3.substr(p3))
            return true;
        
        if(s1[p1]==s3[p3] && search(s1, p1+1, s2, p2, s3, p3+1, visited))
            return true;
        if(s2[p2]==s3[p3] && search(s1, p1, s2, p2+1, s3, p3+1, visited))
            return true;
        
        visited[p1][p2] = true;
        return false;
    
    }
    
};
