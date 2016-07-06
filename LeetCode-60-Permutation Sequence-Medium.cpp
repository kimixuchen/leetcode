/**
LeetCode-60-Permutation Sequence
05/07/16 20:34:05
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    string getPermutation(int n, int k) {
        const int count[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int used[10];
        memset(used, 0, sizeof(used));
        vector<int> candidate(n, 0);
        for(int i=0; i<n; ++i)
        {
            candidate[i] = i+1;
        }
        string ret;
        
        int cn = n;
        int curn = cn;
        int ck = k-1;
        while(ck > 0)
        {
            for(int i=curn-1; i>=0; --i)
            {
                used[i] = ck/count[i];
                if(used[i] > 0)
                {
                    ck %= count[i];
                    curn = i;
                    break;
                }
            }
        }
        
        for(int i=cn-1; i>=0; --i)
        {
            ret += candidate[used[i]] + '0';
            candidate.erase(candidate.begin() + used[i]);
        }
        return ret;
    }
};
