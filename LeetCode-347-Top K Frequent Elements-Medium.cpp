/*
LeetCode-345-Top K Frequent Elements
16/11/16 08:24:02
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
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> ret;
        vector<vector<int>> bucket(nums.size()+1);
        for(int i : nums)
        {
            if(map.find(i)!=map.end())
                map[i]++;
            else
                map[i] = 1;
        }
        for(auto kv = map.begin(); kv != map.end(); ++kv)
        {
            int frequence = kv->second;
            if(bucket[frequence].size() == 0)
            {
                bucket[frequence] = vector<int>();
            }
            bucket[frequence].push_back(kv->first);
        }
        
        int sum = 0;
        for(int i=bucket.size()-1; i>=0; --i)
        {
            if(bucket[i].size() != 0)
            {
                for(int j = 0; j<bucket[i].size(); ++j)
                {
                    ret.push_back(bucket[i][j]);
                    ++sum;
                    if(sum >= k)
                        break;
                }
            }
            if(sum >= k)
                break;
        }
        
        return ret;
        
    }
};
