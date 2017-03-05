/*
LeetCode-514-Freedom Trail
05/03/17 11:16:00
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

class Solution {
private:
    string pring;
    string pkey;
    int visited[105][105];
    int getStep(int pos1, int pos2)
    {
        int len = pring.length();
        return min((pos2-pos1+len)%len, (pos1-pos2+len)%len);
    }
    
    int dfs(int pos1, int keycurpos, int keytargetpos)
    {
        if(keycurpos > keytargetpos)
            return 0;
        if(visited[pos1][keycurpos]>0)
            return visited[pos1][keycurpos];
        
        int minstep = INT_MAX;
        for(int pos2=0; pos2<pring.length(); ++pos2)
        {
            if(pring[pos2]==pkey[keycurpos])
            {
                minstep = min(minstep, getStep(pos1, pos2) + 
                        dfs(pos2, keycurpos+1, keytargetpos));
            }
        }
        visited[pos1][keycurpos] = minstep;
        return minstep;
    }
    
public:
    int findRotateSteps(string ring, string key) {
        pring = ring;
        pkey = key;
        
        int pos1 = 0;
        int pos2 = 0;
        unordered_map<char, int> ringchars;
        for(char c : ring)
        {
            ringchars[c]++;
        }
        
        int steps = 0;
        while(pos2 < key.length())
        {
            if(ring[pos1]==key[pos2])
            {
                ++pos2;
            }
            else
            {
                int nextpos = pos2;
                for( ; nextpos<key.length(); ++nextpos)
                {
                    if(ringchars[key[nextpos]]==1)
                    {
                        break;
                    }
                }
                if(nextpos>=key.length())
                    nextpos--;
                memset(visited, 0, sizeof(visited));
                steps += dfs(pos1, pos2, nextpos);
                pos2 = nextpos+1;
                for(int i=0; i<ring.length(); ++i)
                {
                    if(ring[i]==key[nextpos])
                    {
                        pos1=i;
                        break;
                    }
                }
            }
        }
        
        return steps + key.length();
        
        
    }
};
