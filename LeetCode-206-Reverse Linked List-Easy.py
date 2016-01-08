import heapq
"""
LeetCode-206-Reverse Linked List
08/01/16 14:30:52
xuchen
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cur = head
        newHead = head
        while cur!=None:
            tmp = cur.next
            cur.next = newHead
            newHead = cur
            cur = tmp
        if head:
            head.next = None
        return newHead
        
s = Solution()
print(s.mergeKLists([None, None]))
