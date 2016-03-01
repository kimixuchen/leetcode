"""
LeetCode-102-Binary Tree Level Order Traversal
01/03/16 21:24:04
xuchen
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        retList = []
        nodeList = []
        childList = []
        if root == None:
            return retList
        
        valList = []
        valList.append(root.val)
        nodeList.append(root)
        while len(nodeList) > 0:
            levelNum = len(nodeList)
            retList.append(valList[:])
            valList = []
            while levelNum > 0:
                levelNum-=1
                node = nodeList.pop(0)
                if node.left!=None:
                    nodeList.append(node.left)
                    valList.append(node.left.val)
                if node.right!=None:
                    nodeList.append(node.right)
                    valList.append(node.right.val)
        
        return retList
        
