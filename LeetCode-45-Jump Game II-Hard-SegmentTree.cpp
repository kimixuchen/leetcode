/**
LeetCode-45-Jump Game II
23/05/16 10:25:05
xuchen
SegmentTree, similar to Codeforces #353 DIV2 E
o(n*log(n))
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

typedef pair<int, int> datatype;

class SegmentTree
{
private:
    vector<int> nums;
    int len;
    vector<datatype> tree;

    void pushUp(int o)
    {
        if(tree[o*2].second > tree[o*2+1].second)
            tree[o] = tree[o*2];
        else
            tree[o] = tree[o*2+1];
    }

    void buildTree(int o, int l, int r){
        if(l==r)
        {
            datatype d = make_pair(l, l+nums[l]);
            tree[o] = d;
        }
        else
        {
            int mid = (l+r)>>1;
            buildTree(o*2, l, mid);
            buildTree(o*2+1, mid+1, r);
            pushUp(o);
        }
    }

    datatype queryTree(int a, int b, int l, int r, int o){
        if(a<=l && b>=r)
        {
            return tree[o];
        }
        int mid = (l+r)>>1;
        datatype p1 = make_pair(-1, 0), p2 = make_pair(-1, 0);
        if(a<=mid)
            p1 = queryTree(a, b, l, mid, o*2);
        if(b>mid)
            p2 = queryTree(a, b, mid+1, r, o*2+1);
        
        if(p1.second > p2.second)
            return p1;
        else
            return p2;
    }


public:
    SegmentTree(vector<int>& nums){
        this->nums = nums;
        this->len = nums.size();
        vector<datatype> t(this->len*4, make_pair(-1, 0));
        tree = t;
        build();
    }

    void build(){
        buildTree(1, 0, len-1);
    }

    datatype query(int begin, int end){
        return queryTree(begin, end, 0, len-1, 1);
    
    }
};

class Solution {

public:
    int jump(vector<int>& nums) {
        SegmentTree *tree = new SegmentTree(nums);
        vector<int> h(nums);
        int len = nums.size();
        
        h[len-1] = 0;
        for(int i=len-2; i>=0; --i)
        {
            if(i+nums[i]>=len-1)
            {
                h[i] = 1;
            }
            else if(nums[i]==0)
            {
                continue;
            }
            else
            {
                int m;
                datatype p;
                p = tree->query(i+1, i+nums[i]);
                m = p.first;
                h[i] = h[m] + 1;
            }
        }
        return h[0];
    }
};
