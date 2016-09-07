/**
LeetCode-130-Surrounded Regions
07/09/16 08:44:16
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;
class Solution {
private:
    bool isIn(int row, int col, int x, int y)
    {
        if(x>=0 && x<row && y>=0 && y<col)
            return true;
        else
            return false;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited)
    {
        queue<pair<int, int>> q;
        auto backup = board;
        int row = board.size();
        int col = board[0].size();
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool isBoard = false;
        
        q.push(make_pair(x, y));
        while(!q.empty())
        {
            pair<int, int> point = q.front();
            q.pop();
            int x1=point.first, y1=point.second;
            backup[x1][y1] = 'X';
            
            if(x1==0 || x1==row-1 || y1==0 || y1==col-1)
                isBoard = true;
            for(int i=0; i<4; ++i)
            {
                x1 = point.first + dir[i][0];
                y1 = point.second + dir[i][1];
                if(isIn(row, col, x1, y1) && board[x1][y1]=='O' && !visited[x1][y1])
                {
                    q.push(make_pair(x1, y1));
                    visited[x1][y1] = true;
                }
            }
            
        }
        if(!isBoard)
        {
            board = backup;
        }
        return;
    }

public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q_surroundedO;
        queue<pair<int, int>> q_checkingO;
        if(board.size() == 0)
            return;
        vector<vector<bool>> visited(board.size(), 
                vector<bool>(board[0].size()));
        
        
        for(int i=0; i<board.size(); ++i)
        {
            for(int j=0; j<board[0].size(); ++j)
            {
                if(board[i][j]=='O' && !visited[i][j])
                {
                    dfs(board, i, j, visited);
                }
            }
        }
        
        return;
    }
};
