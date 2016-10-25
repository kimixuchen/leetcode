/*
LeetCode-307-Range Sum Query-Mutable
24/10/16 21:01:58
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

class NumArray {
private:
    vector<int> in;
    vector<int> numscpy;
    
    int lowbit(int n)
    {
        return n&(n^(n-1));
    }
    
    void plus(int pos, int num)
    {
        while(pos<in.size())
        {
            in[pos] += num;
            pos += lowbit(pos);
        }
    }
    
    int sum(int end)
    {
        int sum = 0;
        while(end>0)
        {
            sum += in[end];
            end -= lowbit(end);
        }
        return sum;
    }
    
public:
    NumArray(vector<int> &nums) {
        in = vector<int>(nums.size()+1, 0);
        numscpy = nums;
        for(int i=1; i<=nums.size(); ++i)
        {
            plus(i, nums[i-1]);
        }
    }

    void update(int i, int val) {
        plus(i+1, val-numscpy[i]);
        numscpy[i] = val;
    }

    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);