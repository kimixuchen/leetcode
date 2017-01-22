/**
LeetCode-492-Construct the Rectangle
2017-01-22 19:04:32
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
    	vector<int> ret;
    	int m = (int)sqrt(area);
    	int w, l;
    	for(int i=m; i>=1; --i)
    	{
    		if(area%i==0)
    		{
    			w = i;
    			l = area/w;
    			break;
    		}
    	}

    	ret.push_back(l);
    	ret.push_back(w);

    	return ret;
    }
};
