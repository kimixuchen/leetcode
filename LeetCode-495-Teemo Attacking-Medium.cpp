/**
LeetCode-495-Teemo Attacking
2017-01-30 09:48:57
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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        
        if(timeSeries.size()==0)
        	return total;

        int next = timeSeries[0]+duration;

        for(int i=1; i<timeSeries.size(); ++i)
        {
        	if(timeSeries[i]>=next)
        	{
        		total += duration;
        	}
        	else
        	{
        		total += timeSeries[i]-timeSeries[i-1];
        	}
        	next = timeSeries[i]+duration;
        }
        total += duration;

        return total;
    }
};