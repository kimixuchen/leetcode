/*
LeetCode-454-4Sum II
05/12/16 09:28:10
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
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sum1;
        unordered_map<int, int> sum2;
        int ret = 0;
        
        for(int a : A)
        {
            for(int b : B)
            {
                int sum = a+b;
                if(sum1.find(sum)!=sum1.end())
                    sum1[sum]++;
                else
                    sum1[sum] = 1;
            }
        }
        
        for(int c : C)
        {
            for(int d : D)
            {
                int sum = c+d;
                if(sum1.find(-sum) != sum1.end())
                {
                    ret += sum1[-sum];
                }
            }
        }
        
        return ret;
        
    }
};
