/*
 * Leetcode 655-Coin Path
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
private:
    bool smaller(vector<int> &a, int c, vector<int> &b) {
        if(b.size() == 0)
            return true;
        a.push_back(c);
        
        int ret = -1;
        for(int i=0; i<a.size() && i<b.size(); i++) {
            if(a[i] < b[i])
                ret = 1;
            else if(a[i] > b[i])
                ret = 0;
        }
        a.pop_back();
        if(ret == 0)
            return false;
        if(ret == 1)
            return true;
        if(a.size()+1 > b.size())
            return false;
        else
            return true;
    }
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        vector<vector<int>> paths(n, vector<int>());
        vector<int> costs(n, INT_MAX);
        
        paths[0].push_back(1);
        costs[0] = 0;
        for(int i=0; i<n-1; i++) {
            if(A[i] == -1)
                continue;
            for(int j=1; j<=B && i+j<n; j++) {
                if(A[i+j] == -1) 
                    continue;
                if(paths[i].size() > 0) {
                    if(costs[i] + A[i+j] < costs[i+j] || 
                    (costs[i] + A[i+j] == costs[i+j] && smaller(paths[i], i+j+1, paths[i+j]))) {
                        costs[i+j] = costs[i] + A[i+j];
                        paths[i+j] = paths[i];
                        paths[i+j].push_back(i+j+1);
                    }
                }
            }
        }
        return paths[n-1];
    }
};







