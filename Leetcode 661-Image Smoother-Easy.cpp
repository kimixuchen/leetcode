/*
 * Leetcode 661-Image Smoother
 */
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        int dirs[9][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                          {0, -1}, {0, 0}, {0, 1},
                          {1, -1}, {1, 0}, {1, 1}};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int sum = 0;
                int t = 0;
                for(int k=0; k<9; k++){
                    int x = i+dirs[k][0];
                    int y = j+dirs[k][1];
                    if(x>=0 && x<m && y>=0 && y<n) {
                        sum += M[x][y];
                        t++;
                    }
                }
                ret[i][j] = sum/t;
            }
        }
        
        return ret;
        
    }
};














