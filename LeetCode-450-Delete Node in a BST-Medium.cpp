/*
LeetCode-450-Delete Node in a BST
13/01/17 13:23:14
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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    struct NodePair{
        TreeNode *parent;
        TreeNode *cur;
    };
    
    NodePair search(TreeNode *root, int key)
    {
        TreeNode *parent = NULL;
        TreeNode *cur = root;
        while(cur != NULL)
        {
            if(cur->val == key)
            {
                break;
            }
            else if(cur->val > key)
            {
                parent = cur;
                cur = cur->left;
            }
            else
            {
                parent = cur;
                cur = cur->right;
            }
        }
        
        NodePair ret;
        ret.parent = parent;
        ret.cur = cur;
        
        return ret;
    }
    
    NodePair getRightMin(TreeNode *cur)
    {
        TreeNode *parent = cur;
        TreeNode *node = cur->right;
        while(node->left != NULL)
        {
            parent = node;
            node = node->left;
        }
        NodePair ret;
        ret.parent = parent;
        ret.cur = node;
        
        return ret;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        NodePair searchPair = search(root, key);
        if(searchPair.cur==NULL)
        {
            return root;
        }
        
        TreeNode *nodeDel = searchPair.cur;
        TreeNode *parent = searchPair.parent;
        //printf("%d %d\n", parent->val, nodeDel->val);
        if(parent == NULL)   //root
        {
            //printf("%d\n", nodeDel->val);
            if(nodeDel->left==NULL && nodeDel->right==NULL)
            {
                delete nodeDel;
                root=NULL;
            }
            else if(nodeDel->left==NULL)
            {
                root = nodeDel->right;
                delete nodeDel;
            }
            else if(nodeDel->right==NULL)
            {
                root = nodeDel->left;
                delete nodeDel;
            }
            else
            {
                NodePair rightMinPair = getRightMin(nodeDel);
                swap(nodeDel->val, rightMinPair.cur->val);
                if(rightMinPair.parent->right == rightMinPair.cur)
                {
                    rightMinPair.parent->right = deleteNode(rightMinPair.cur,
                            key);
                }
                else
                {
                    rightMinPair.parent->left = deleteNode(rightMinPair.cur,
                            key);
                }
            }
        }
        else
        {
            if(nodeDel->left==NULL && nodeDel->right==NULL)
            {
                if(parent->left==nodeDel)
                {
                    parent->left=NULL;
                }
                else
                {
                    parent->right=NULL;
                }
                delete nodeDel;
            }
            else if(nodeDel->left==NULL)
            {
                if(parent->left==nodeDel)
                {
                    parent->left = nodeDel->right;
                }
                else
                {
                    parent->right = nodeDel->right;
                }
                delete nodeDel;
            }
            else if(nodeDel->right==NULL)
            {
                if(parent->left==nodeDel)
                {
                    parent->left = nodeDel->left;
                }
                else
                {
                    parent->right = nodeDel->left;
                }
                delete nodeDel;
            }
            else
            {
                NodePair rightMinPair = getRightMin(nodeDel);
                //printf("%d %d\n", rightMinPair.parent->val, 
                //        rightMinPair.cur->val);
                swap(nodeDel->val, rightMinPair.cur->val);
                if(rightMinPair.parent->right == rightMinPair.cur)
                {
                    rightMinPair.parent->right = deleteNode(rightMinPair.cur,
                            key);
                }
                else
                {
                    rightMinPair.parent->left = deleteNode(rightMinPair.cur,
                            key);
                }
            }
        }
        return root;
        
    }
};
