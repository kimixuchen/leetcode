/*
LeetCode-498-Diagonal traverse
05/02/17 11:10:30
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

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size()==0)
            return ret;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int px = 0, py = 0;
        int dir = 0;    //0:up  1:down
        while(px<m && py<n)
        {
            ret.push_back(matrix[px][py]);
            //printf("%d ", matrix[px][py]);
            
            if(px==m-1 && py==n-1)
                break;
            
            if(dir==0)
            {
                if(px>0 && py<n-1)
                {
                    --px;
                    ++py;
                }
                else if(px==0 && py<n-1)
                {
                    ++py;
                    dir = 1;
                }
                else
                {
                    ++px;
                    dir = 1;
                }
            }
            else
            {
                if(px<m-1 && py>0)
                {
                    ++px;
                    --py;
                }
                else if(px<m-1 && py==0)
                {
                    ++px;
                    dir = 0;
                }
                else
                {
                    ++py;
                    dir = 0;
                }
            }
        }
        return ret;
    }
};
