"""
LeetCode-Count of Smaller Numbers After Self
2015-12-08 10:15:10
xuchen
"""
class Node(object):
    def __init__(self, val):
        self.selfsize=1
        self.leftsize=0
        self.val=val
        self.left=None
        self.right=None

class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        if length==0:
            return []

        root = Node(nums[length-1]) 
        retList = []
        retList.append(0)
        for i in range(length-2, -1, -1):
            retList.insert(0, self.getCount(root, nums[i]))
        
        return retList
    
    def getCount(self, root, val):
        num = 0
        while True:
            if root.val<val:
                num += root.selfsize+root.leftsize
                if root.right==None:
                    tmp = Node(val)
                    root.right = tmp
                    break
                root = root.right
            elif root.val>val:
                root.leftsize+=1
                if root.left==None:
                    tmp = Node(val)
                    root.left = tmp
                    break
                root = root.left
            else:
                root.selfsize+=1
                num += root.leftsize
                break
        return num
