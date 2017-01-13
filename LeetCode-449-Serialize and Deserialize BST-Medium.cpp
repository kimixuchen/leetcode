/*
LeetCode-449-Serialize and Deserialize BST
13/01/17 09:25:49
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
class Codec {
private:
    TreeNode* buildTree(vector<int> &elems, int start, int end)
    {
        if(start > end)
            return NULL;
        
        TreeNode *cur = new TreeNode(elems[start]);
        int pos = start;
        for( ; pos<=end; ++pos)
        {
            if(elems[pos] > elems[start])
            {
                break;
            }
        }
        cur->left = buildTree(elems, start+1, pos-1);
        cur->right = buildTree(elems, pos, end);
        
        return cur;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> elems;
        stack<TreeNode*> nodestack;
        nodestack.push(root);
        
        while(!nodestack.empty())
        {
            TreeNode *cur = nodestack.top();
            nodestack.pop();
            if(cur==NULL)
                continue;
            elems.push_back(cur->val);
            
            if(cur->right!=NULL)
                nodestack.push(cur->right);
            if(cur->left!=NULL)
                nodestack.push(cur->left);
        }
        
        string serializeStr;
        for(int i=0; i+1<elems.size(); ++i)
        {
            serializeStr += to_string(elems[i]);
            serializeStr += ",";
        }
        if(elems.size() > 0)
            serializeStr += to_string(elems.back());
        
        //cout<<serializeStr<<endl;
        return serializeStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> elems;
        stringstream sstr(data);
        string token;
        while(getline(sstr, token, ','))
        {
            elems.push_back(stoi(token));
        }
        /**
        for(int i : elems)
            printf("%d ", i);
        printf("\n");
        **/
        
        TreeNode *root = buildTree(elems, 0, elems.size()-1);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
