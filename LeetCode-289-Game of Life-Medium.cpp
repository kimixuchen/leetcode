/**
LeetCode-289-Game of Life
20/10/16 09:03:24
xuchen
**/

#include <iostream>
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
private:
    bool isOk(int x, int y, int m, int n)
    {
        return x>=0 && x<m && y>=0 && y<n;
    
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m<1)
            return;
        int n = board[0].size();
        int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, 
            {1, -1}, {1, 0}, {1, 1}};
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                int x, y;
                int counter = board[i][j]/2;
                board[i][j] %= 2;
                for(int k=0; k<8; ++k)
                {
                    x = i+dir[k][0];
                    y = j+dir[k][1];
                    if(isOk(x, y, m, n) && (x>i || (x==i&&y==j+1)))
                    {
                        counter += board[x][y]%2;
                        if(board[i][j]==1)
                            board[x][y] += 2;
                    }
                }
                
                if(board[i][j] == 1)
                {
                    if(counter < 2 || counter > 3)
                        board[i][j] = 0;
                }
                else
                {
                    if(counter == 3)
                        board[i][j] = 1;
                }
            }
        }
        
        return;
        
    }
};
