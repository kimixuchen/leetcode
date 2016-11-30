/*
LeetCode-406-Queue Reconstruction by Height
30/11/16 09:04:19
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
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        if(p1.first < p2.first)
            return false;
        else if(p1.first > p2.first)
            return true;
        else
        {
            return p1.second < p2.second;
        }
    }
    
    void shift(vector<pair<int, int>> &orderp, int pos1, int pos2)
    {
        pair<int, int> tmp = orderp[pos2];
        for(int i=pos2; i>pos1; --i)
            orderp[i] = orderp[i-1];
        
        orderp[pos1] = tmp;
        
        return;
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> orderp = people;
        sort(orderp.begin(), orderp.end(), cmp);
        
        for(int i=0; i<orderp.size(); ++i)
        {
            if(orderp[i].second < i)
            {
                shift(orderp, orderp[i].second, i);
            }
        }
        
        return orderp;
        
    }
};
