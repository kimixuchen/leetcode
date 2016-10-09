/**
LeetCode-220-Contains Duplicate III
09/10/16 09:59:47
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

struct node{
    int val;
    node *left, *right;
    node(int v){
        val = v;
        left = right = NULL;
    }
};

class Solution {
private:
    void deleteNode(node **root, int val)
    {
        node *cur = *root;
        node *pre = *root;
        while(cur != NULL)
        {
            if(cur->val == val)
                break;
            pre = cur;
            if(val < cur->val)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        node *left = cur->left, *right = cur->right;
        if(left==NULL && right==NULL)
        {
            if(pre->left==cur)
                pre->left = NULL;
            else
                pre->right = NULL;
            
            free(cur);
        }
        else if(left==NULL && right!=NULL)
        {
            if(pre==cur)
            {
                *root = cur->right;
            }
            else if(pre->left==cur)
            {
                pre->left = cur->right;
            }
            else
            {
                pre->right = cur->right;
            }
            free(cur);
        }
        else if(left!=NULL && right==NULL)
        {
            if(pre==cur)
            {
                *root = cur->left;
            }
            else if(pre->left==cur)
            {
                pre->left = cur->left;
            }
            else
            {
                pre->right = cur->left;
            }
            free(cur);
        }
        else
        {
            node *t = getMax(left);
            int v = t->val;
            deleteNode(root, v);
            cur->val = v;
        }
    }

    node *getMax(node *root)
    {
        node *cur = root;
        while(cur->right!= NULL)
        {
            cur = cur->right;
        }
        return cur;
    }

    
    void insertNode(node *root, int val)
    {
        node *cur = root;
        node *pre = root;
        while(cur != NULL)
        {
            pre = cur;
            if(val < cur->val)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        if(val < pre->val)
            pre->left = new node(val);
        else
        {
            pre->right = new node(val);
        }
    }
    
    bool contains(node *root, int val, int t)
    {
        node *cur = root;
        while(cur != NULL)
        {
            if(val >= cur->val-t && val <= cur->val+t)
                return true;
            if(val < cur->val)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        return false;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()==0)
            return false;
        node *root = new node(nums[0]);
        int pos = 1;
        for( ;pos<=k && pos<nums.size(); ++pos)
        {
            if(contains(root, nums[pos], t))
                return true;
            insertNode(root, nums[pos]);
        }
        
        while(pos < nums.size())
        {
            deleteNode(&root, nums[pos-1-k]);
            if(contains(root, nums[pos], t))
                return true;
            insertNode(root, nums[pos]);
            ++pos;
        }
        return false;
        
    }
};
