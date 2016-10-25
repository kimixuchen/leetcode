/*
LeetCode-310-Minimum Height Trees
25/10/16 09:55:28
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
private:

    vector<int> dfs(vector<vector<int>> &adj, int root, int fa)
    {
        vector<int> childs;
        vector<int> nexts = adj[root];
        for(int i =0; i<nexts.size(); ++i)
        {
            int child = adj[root][i];
            if(child!=fa)
            {
                auto tmp = dfs(adj, child, root);
                if(childs.size() < tmp.size())
                    childs = tmp;
            }
        }
        childs.insert(childs.begin(), root);
        return childs;
    }
    
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        if(n==0)
            return ret;
        vector<vector<int>> adj(n);
        
        for(auto e : edges)
        {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        vector<int> path1 = dfs(adj, 0, -1);
        int v1 = path1.back();
        vector<int> ds = dfs(adj, v1, -1);
        
        if(ds.size()%2==1)
        {
            ret.push_back(ds[ds.size()/2]);
        }
        else
        {
            ret.push_back(ds[ds.size()/2]);
            ret.push_back(ds[ds.size()/2-1]);
        }
        
        return ret;
    }
};

