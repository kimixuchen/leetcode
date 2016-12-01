/*
LeetCode-419-Battleships in a Board
01/12/16 09:44:14
xuchen
**/

#include <iostream>
#include <sstream>
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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int counter = 0;
        int m = board.size();
        if(m==0)
            return 0;
        int n = board[0].size();
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(board[i][j]=='X')
                {
                    ++counter;
                    //horizontally
                    if(j+1<n && board[i][j+1]=='X')
                        --counter;
                    
                    //vertically
                    if(i+1<m && board[i+1][j]=='X')
                        --counter;
                }
            }
        }
        return counter;
        
    }
};
