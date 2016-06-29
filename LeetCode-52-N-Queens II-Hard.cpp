/**
LeetCode-52-N-Queens II
29/06/16 09:11:35
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
private:
    bool isOk(int n, int x, int y, vector<bool> &okRow, vector<bool> &okCol,
            vector<bool> &okDiagonal1, vector<bool> &okDiagonal2)
    {
        int a, b;
        if(x>=y)
        {
            a = x-y;
        }
        else
        {
            a = n+y-x;
        }
        
        if(x+y<=n-1)
        {
            b = x+y;
        }
        else
        {
            b = x+y+1;
        }
        if(okRow[x] && okCol[y] && okDiagonal1[a] && okDiagonal2[b])
        {
            okRow[x] = false;
            okCol[y] = false;
            okDiagonal1[a] = false;
            okDiagonal2[b] = false;
            return true;
        }
        return false;
    }

    void update(int n, int x, int y, vector<bool> &okRow, vector<bool> &okCol,
            vector<bool> &okDiagonal1, vector<bool> &okDiagonal2)
    {
        int a, b;
        if(x>=y)
        {
            a = x-y;
        }
        else
        {
            a = n+y-x;
        }
        
        if(x+y<=n-1)
        {
            b = x+y;
        }
        else
        {
            b = x+y+1;
        }
        okRow[x] = true;
        okCol[y] = true;
        okDiagonal1[a] = true;
        okDiagonal2[b] = true;
    }


public:
    int totalNQueens(int n) {
        vector<vector<int>> board;
        vector<bool> okRow(n, true);
        vector<bool> okCol(n, true);
        vector<bool> okDiagonal1(n*2, true);
        vector<bool> okDiagonal2(n*2, true);
        
        string base(n, '.');
        int ans = 0;
        vector<int> line(n, 0);
        vector<int> pos(n, -1);
        for(int i=0; i<n; ++i)
        {
            board.push_back(line);
        }
        int level = 0;
        while(level >= 0)
        {
            if(pos[level]>-1)
            {
                board[level][pos[level]] = 0;
                update(n, level, pos[level], okRow, okCol, okDiagonal1, okDiagonal2);
            }
            
            int i = pos[level]+1;
            for( ; i<n; ++i)
            {
                board[level][i] = 1;
                if(isOk(n, level, i, okRow, okCol, okDiagonal1, okDiagonal2))
                {
                    pos[level] = i;
                    break;
                }
                board[level][i] = 0;
            }
            if(i < n)
            {
                if(level == n-1)
                {
                    ++ans;
                    pos[level] = -1;
                    board[level][i] = 0;
                    update(n, level, i, okRow, okCol, okDiagonal1, okDiagonal2);
                    --level;
                }
                else
                {
                    ++level;
                }
            }
            else
            {
                pos[level] = -1;
                --level;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int ans = 0;
    for(int i=8; i<9; ++i)
    {
        ans += s.solveNQueens(i);
    }
    return 0;
}
