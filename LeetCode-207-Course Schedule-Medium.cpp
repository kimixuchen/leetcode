/**
LeetCode-207-Course Schedule
26/09/16 09:34:32
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>> 
            &prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);
        for(pair<int, int> req : prerequisites)
        {
            graph[req.first].insert(req.second);
        }
        return graph;
    }
    
    bool dfs(vector<unordered_set<int>> &graph, vector<bool> &visited, 
            vector<bool> &onpath, int i)
    {
        if(visited[i])
            return false;
        
        visited[i] = true;
        onpath[i] = true;
        for(int j : graph[i])
        {
            if(onpath[j] || dfs(graph, visited, onpath, j))
                return true;
        }
        
        return onpath[i] = false;
    }
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);
        
        for(int i=0; i<numCourses; ++i)
        {
            if(!visited[i] && dfs(graph, visited, onpath, i))
                return false;
        }
        return true;
    }
};
