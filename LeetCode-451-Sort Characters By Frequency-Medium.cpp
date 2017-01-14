/*
LeetCode-451-Sort Characters By Frequency
14/01/17 20:21:21
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

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> chars;
        vector<string> buckets(s.size()+1, "");
        
        for(char c : s)
            chars[c]++;
        for(auto &it : chars)
        {
            int c = it.first;
            int n = it.second;
            buckets[n].append(n, c);
        }
        string ret;
        for(int i=s.size(); i>=0; --i)
        {
            if(buckets[i] != "")
                ret.append(buckets[i]);
        }
        return ret;
        
        
    }
};
