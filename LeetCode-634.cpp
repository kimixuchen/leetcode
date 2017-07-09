/*
 *634. Find the Derangement of An Array
 */
#include <iostream>
#include "limits.h"
using namespace std;

class Solution {
public:
    int findDerangement(int n) {
        const int MOD = 1e9 + 7;
        long long ret=0;

        for(int i=2; i<=n; i++) {
            ret = ((i*ret % MOD) + (i%2==0 ? 1:-1)) % MOD;
        }

        return (int)ret;
    }
};