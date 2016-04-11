/**
LeetCode-42-Trapping Rain Water
11/04/16 12:18:31
xuchen
**/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> righthigh(height);
        int high=0, sum=0, ans=0, width=0;
        for(int i=len-1; i>=0; --i)
        {
            righthigh[i]=high;
            if(height[i] > high)
                high = height[i];
        }
        int i=0;
        int pos;
        while(i<len)
        {
            if(height[i] > righthigh[i])
                height[i] = righthigh[i];
            pos = i+1;
            while(height[i]>height[pos] && pos<len)
            {
                ++width;
                sum += height[pos];
                ++pos;
            }
            ans += (width*height[i]-sum);
            width=0;
            sum=0;
            i=pos;
        }
        return ans;
    }
};
