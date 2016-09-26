/**
LeetCode-204-Count Primes
26/09/16 08:48:47
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
    int countPrimes(int n) {
        int sqrtHalf = sqrt(n)+1;
        vector<bool> isPrime(n+1, true);
        int count=0;
        for(int i=2; i<=sqrtHalf; ++i)
        {
            if(isPrime[i])
            {
                for(int j=i*i; j<n; j+=i)
                    isPrime[j] = false;
            }
        }
        for(int i=2; i<n; ++i)
            if(isPrime[i])
                ++count;
        
        return count;
        
    }
};
