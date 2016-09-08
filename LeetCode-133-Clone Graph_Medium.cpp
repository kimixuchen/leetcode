/**
LeetCode-133-Clone Graph
08/09/16 08:36:08
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    UndirectedGraphNode* dfs(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& visited)
    {
        if(visited.count(node->label) > 0)
            return visited[node->label];
        
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        visited[node->label] = root;
        for(auto it = node->neighbors.begin(); it != node->neighbors.end(); ++it)
        {
            root->neighbors.push_back(dfs(*it, visited));
        }
        
        return root;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
            return NULL;
        unordered_map<int, UndirectedGraphNode*> visited;
        return dfs(node, visited);
    }
};
