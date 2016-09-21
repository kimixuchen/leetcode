/**
LeetCode-168-Excel Sheet Column Title
21/09/16 09:16:36
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    string convertToTitle(int n) {
        const int BASE = 26;
        
        string title;
        int res = n;
        while(res > 0)
        {
            title += (res-1)%BASE+'A';
            res = (res-1)/BASE;
        }
        reverse(title.begin(), title.end());
        
        return title;
        
    }
};
