/*
LeetCode-529-Minesweeper
27/02/17 08:58:14
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
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int x = click[0];
        int y = click[1];
        
        vector<vector<char>> cpboard = board;
        if(cpboard[x][y]=='M')
        {
            cpboard[x][y] = 'X';
            return cpboard;
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        
        int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, 
            {1, -1}, {1, 0}, {1, 1}};
        while(!q.empty())
        {
            pair<int, int> point = q.front();
            q.pop();
            if(cpboard[point.first][point.second] != 'E')
                continue;
            
            int count = 0;
            for(int i=0; i<8; ++i)
            {
                int x = point.first+dirs[i][0];
                int y = point.second+dirs[i][1];
                
                if(x>=0 && x<m && y>=0 && y<n && cpboard[x][y]=='M')
                {
                    ++count;
                }
            }
            
            if(count>0)
            {
                cpboard[point.first][point.second] = count+'0';
            }
            else
            {
                for(int i=0; i<8; ++i)
                {
                    int x = point.first+dirs[i][0];
                    int y = point.second+dirs[i][1];
                    
                    if(x>=0 && x<m && y>=0 && y<n && cpboard[x][y]=='E')
                    {
                        q.push(make_pair(x, y));
                    }
                }
                cpboard[point.first][point.second] = 'B';
            }
        }
        
        return cpboard;
        
    }
};
