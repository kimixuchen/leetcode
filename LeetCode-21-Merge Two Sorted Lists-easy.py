"""
LeetCode-21-Merge Two Sorted Lists
06/01/16 09:39:54
xuchen
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        retl = ListNode(0)
        curNode = retl
        while l1!=None and l2!=None:
            if l1.val<l2.val:
                newNode = ListNode(l1.val)
                l1 = l1.next
            else:
                newNode = ListNode(l2.val)
                l2 = l2.next
            curNode.next = newNode
            curNode = curNode.next
        
        if l1==None:
            l1 = l2
        curNode.next = l1
        retl = retl.next
        
        return retl
        
