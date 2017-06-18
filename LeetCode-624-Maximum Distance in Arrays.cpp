/**
LeetCode-624-Maximum Distance in Arrays
2017-06-18 09:34:14
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1Pos, min2Pos, max1Pos, max2Pos;

        int n = arrays.size();
        for(int i=0; i<n; i++) {
            int a = arrays[i][0];
            int b = arrays[i].back();
            if(min1 > a) {
                min2 = min1;
                min2Pos = min1Pos;
                min1 = a;
                min1Pos = i;
            }
            else if(min2 > a) {
                min2 = a;
                min2Pos = i;
            }

            if(max1 <= b) {
                max2 = max1;
                max2Pos = max1Pos;
                max1 = b;
                max1Pos = i;
            }
            else if(max2 <= b) {
                max2 = b;
                max2Pos = i;
            }
        }

        if(min1Pos == max1Pos) {
            return max(abs(min1-max2), abs(min2-max1));
        }
        
        return abs(min1-max1);
    }
};