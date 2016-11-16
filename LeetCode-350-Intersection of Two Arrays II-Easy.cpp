/*
LeetCode-350-Intersection of Two Arrays II
16/11/16 09:06:46
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> ret;
        
        for(int i : nums1)
        {
            if(map.find(i)!=map.end())
                map[i]++;
            else
                map[i] = 1;
        }
        
        for(int i : nums2)
        {
            if(map.find(i)!=map.end() && map[i]>0)
            {
                map[i]--;
                ret.push_back(i);
            }
        }
        
        return ret;
    }
};
