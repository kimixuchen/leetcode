/**
LeetCode Weekly Contest 5-Nth Digit
18/09/16 09:30:47
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
    int findNthDigit(int n) {
        if(n<10)
            return n;
        int level = 1;
        long long sum = 0;
        while(sum < n)
        {
            sum += pow(10, level-1)*9*level;
            level++;
        }
        level--;
        sum -= pow(10, level-1)*9*level;
        n -= sum;
        n--;
        int index = n/level;
        int m = n%level;
        int ret;
        index += pow(10, level-1);
        for(int i=level-1; i>=m; --i)
        {
            ret = index%10;
            index/=10;
        }
        
        return ret;
        
        
    }
};

int main()
{
    Solution s;
    cout<<s.findNthDigit(1000000000);

    return 0;
}
