import heapq
"""
LeetCode-24-Swap Nodes in Pairs
07/01/16 10:25:16
xuchen
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        length = 0
        curNode = head
        while curNode!=None:
            length+=1
            curNode = curNode.next
        
        if length<2:
            return head
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        pos1 = dummy
        pos2 = dummy
        for i in range(0, length/2):
            pre = pos1
            pos2 = pos1.next.next
            pos1 = pos1.next
            pos1.next = pos2.next
            pos2.next = pos1
            pre.next = pos2
        return dummy.next
s = Solution()
print(s.mergeKLists([None, None]))
