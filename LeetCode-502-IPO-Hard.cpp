/*
LeetCode-502-IPO
07/02/17 09:40:25
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <priority_queue>
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

class cmpC
{
public:
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs)
        const
    {
        return lhs.second > rhs.second;
    }
};

class cmpP
{
public:
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs)
        const
    {
        return lhs.first < rhs.first;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmpC> pqc;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmpP> pqp; 
        
        int n = Profits.size();
        for(int i=0; i<n; ++i)
        {
            pqc.push(make_pair(Profits[i], Capital[i]));
        }
        
        for(int i=0; i<k; ++i)
        {
            while(!pqc.empty() && pqc.top().second <= W)
            {
                pqp.push(pqc.top());
                pqc.pop();
            }
            if(pqp.empty())
                break;
            
            W += pqp.top().first;
            pqp.pop();
        }
        
        return W;
    }
};
