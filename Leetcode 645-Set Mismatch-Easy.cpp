/*
 * Leetcode 645-Set Mismatch
 */
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
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i : nums) {
            if(m.find(i) == m.end()) {
                m[i] = 1;
            }
            else {
                m[i]++;
            }
        }
        
        vector<int> ret;
        int numMiss, numTwice;
        for(int i=0; i<n; i++) {
            if(m.find(i+1) == m.end()) {
                numMiss = i+1;
            }
            else if(m[i+1] == 2) {
                numTwice = i+1;
            }   
        }
        ret.push_back(numTwice);
        ret.push_back(numMiss);
        
        return ret;
    }
};
