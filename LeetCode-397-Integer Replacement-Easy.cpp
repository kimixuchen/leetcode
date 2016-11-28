/*
LeetCode-397-Integer Replacement
28/11/16 09:12:38
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
    int integerReplacement(int n) {
        unordered_set<long long> visited;
        queue<long long> q;
        q.push(n);
        bool isFind = false;
        
        int step = 0;
        while(!q.empty())
        {
            int m = q.size();
            for(int i=0; i<m; ++i)
            {
                long long a = q.front();
                q.pop();
                //printf("%d ", a);
                if(a==1)
                {
                    isFind = true;
                    break;
                }
                if(visited.find(a)!=visited.end())
                    continue;
                
                visited.insert(a);
                if(a%2==0)
                    q.push(a/2);
                else
                {
                    q.push(a-1);
                    if(a+1 < (long long)n*2)
                    {
                        q.push(a+1);
                    }
                }
            }
            //printf("\n");
            if(isFind)
                break;
            ++step;
        }
        
        return step;
    }
};
