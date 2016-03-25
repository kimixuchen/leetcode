/**
LeetCode-58-Length of Last Word
25/03/16 09:17:00
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
    int lengthOfLastWord(string s) {
        int len = s.length();
        int ans=0;
        for(int i=len-1; i>=0; --i)
        {
            if(s[i]==' ')
            {
                if(ans!=0)
                    break;
            }
            else
                ++ans;
        }
        return ans;
        
    }
};
