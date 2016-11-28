/*
LeetCode-399-Evaluate Division
28/11/16 10:21:35
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
private:
    const double ERROR = -1.0;
    
    struct Edge{
        string to;
        double val;
        Edge(string t, double v)
        {
            to = t;
            val = v;
        }
    };
    
    double bfs(unordered_map<string, vector<Edge>> &graph, string from, string to,
            unordered_set<string> &visited)
    {
        //cout<<from<<" "<<to<<" "<<endl;
        if(graph.find(from) == graph.end())
            return ERROR;
        
        if(from == to)
            return 1.0;
        
        visited.insert(from);
        
        double ans = ERROR;
        for(Edge edge : graph[from])
        {
            double curans = edge.val;
            if(edge.to == to)
            {
                ans = curans;
                break;
            }
            if(visited.find(edge.to) == visited.end())
            {
                curans = curans * bfs(graph, edge.to, to, visited);
                if(curans > 0)
                {
                    ans = curans;
                    break;
                }
            }
        }
        //cout<<from<<" "<<to<<" "<<ans<<endl;
        return ans;
    }

public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<Edge>> graph;
        vector<double> ret;
        
        for(int i=0; i<equations.size(); ++i)
        {
            string from = equations[i].first;
            string to = equations[i].second;
            Edge e1(to, values[i]);
            Edge e2(from, 1/values[i]);
            
            if(graph.find(from) == graph.end())
            {
                graph[from] = vector<Edge>();
            }
            graph[from].push_back(e1);
            
            if(graph.find(to) == graph.end())
            {
                graph[to] = vector<Edge>();
            }
            graph[to].push_back(e2);
        }
        
        for(auto query : queries)
        {
            unordered_set<string> visited;
            double ans = bfs(graph, query.first, query.second, visited);
            ret.push_back(ans);
        }
        
        return ret;
    }
};
