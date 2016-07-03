/**
LeetCode-67-Add Binary
03/07/16 09:50:11
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int posa = a.length()-1;
        int posb = b.length()-1;
        int c = 0;
        while( posa>=0 || posb>=0 || c>0 )
        {
            c += posa>=0 ? a[posa]-'0':0;
            c += posb>=0 ? b[posb]-'0':0;
            ret = char(c%2 + '0') + ret;
            c/=2;
            --posa;
            --posb;
        }
        
        return ret;
    }
};
