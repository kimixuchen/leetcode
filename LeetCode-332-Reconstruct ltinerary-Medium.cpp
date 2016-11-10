/*
LeetCode-332-Reconstruct ltinerary
10/11/16 09:50:02
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
    struct Node{
        set<string> nexts;
        unordered_map<string, int> visitnum;
        unordered_map<string, int> ticnum;
    };
    
    bool dfs(unordered_map<string, Node> &cities, string cur, vector<string> &ret,
            int k, int counter)
    {
        if(k==counter)
            return true;
        
        Node *n = &(cities[cur]);
        for(string s : n->nexts)
        {
            if(n->visitnum[s] < n->ticnum[s])
            {
                n->visitnum[s]++;
                ret.push_back(s);
                if(dfs(cities, s, ret, k+1, counter))
                    return true;
                else
                {
                    n->visitnum[s]--;
                    ret.pop_back();
                }
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, Node> cities;
        int counter=0;
        for(auto p : tickets)
        {
            ++counter;
            if(cities.find(p.first)==cities.end())
            {
                cities[p.first] = Node();
            }
            cities[p.first].nexts.insert(p.second);
            cities[p.first].ticnum[p.second]++;
        }
        ++counter;
        vector<string> ret;
        ret.push_back("JFK");
        dfs(cities, "JFK", ret, 1, counter);
        
        return ret;
    }
};
