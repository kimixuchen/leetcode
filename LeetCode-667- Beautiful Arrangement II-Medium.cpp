/*
LeetCode-667- Beautiful Arrangement II
2017-09-01
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
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        int num1 = 1, num2 = n;
        int turn = 0;
        ret.push_back(num1);
        num1++;
        for(int i=0; i<k-1; i++) {
            if(turn == 1) {
                ret.push_back(num1);
                num1++;
            }
            else {
                ret.push_back(num2);
                num2--;
            }
            turn++;
            turn %= 2;
        }
        if(turn == 1)
            while(num1 <= num2)
                ret.push_back(num2--);
        else
            while(num1 <= num2)
                ret.push_back(num1++);
        
        return ret;
    }
};
