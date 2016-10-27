/*
LeetCode-326-Power of Three
27/10/16 10:36:04
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
    bool isPowerOfThree(int n) {
        //1162261467 is 3^19, 3^20 is greater than int
        return n>0 && (1162261467%n==0);
    }
};
