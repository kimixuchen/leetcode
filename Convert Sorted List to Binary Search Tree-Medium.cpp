/**
Convert Sorted List to Binary Search Tree
29/08/16 10:26:47
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* node;
    TreeNode* inorderHelper(int left, int right)
    {
        if(left > right)
            return NULL;    
        
        int mid = left + (right-left)/2;
        TreeNode* leftNode = inorderHelper(left, mid-1);
        TreeNode* root = new TreeNode(node->val);
        node = node->next;
        root->left = leftNode;
        TreeNode* rightNode = inorderHelper(mid+1, right);
        root->right = rightNode;
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        node = head;
        int size=0;
        while(cur != NULL)
        {
            cur = cur->next;
            ++size;
        }
        return inorderHelper(0, size-1);
    }
};
