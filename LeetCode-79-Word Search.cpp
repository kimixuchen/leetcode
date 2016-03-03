/**
LeetCode-79-Word Search
03/03/16 15:01:26
xuchen
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        if(word.size() <=0 )
            return false;
        int row, col;
        row = board.size();
        if(row <= 0)
            return false;
        col = board[0].size();
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(isExist(board, i, j, row, col, word.c_str()))
                    return true;
            }
        }
        return false;
    }

    bool isExist(vector< vector<char> >& board, int x, int y, int row, 
            int col, const char * cstr)
    {
        if (*cstr == '\0')
        {
            printf("%d %d\n", x, y);
            return true;
        }
        if (x<0 || x>=row || y<0 || y>=col)
            return false;
        if(board[x][y] == *cstr)
        {
            board[x][y] ^= 64;
            if(isExist(board, x-1, y, row, col, cstr+1) || 
                isExist(board, x+1, y, row, col, cstr+1) || 
                isExist(board, x, y-1, row, col, cstr+1) || 
                isExist(board, x, y+1, row, col, cstr+1)) 
            {
                board[x][y] ^= 64;
                printf("%d %d\n", x, y);
                return true;
            }
            board[x][y] ^= 64;
        }
        return false;
    }
};

int main()
{
    vector< vector<char> > s;
    s.push_back("ab");
    ss = "ba";
    s = Solution();
    printf("%b\n", s.exist(s, ss));
    return 0;
}
