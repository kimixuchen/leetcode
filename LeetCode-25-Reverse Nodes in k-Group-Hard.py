import heapq
"""
LeetCode-25-Reverse Nodes in k-Group
08/01/16 14:48:35
xuchen
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, pre, k):
        head = pre.next
        cur = head.next
        newHead = head
        count = 1
        while count < k:
            tmp = cur.next
            cur.next = newHead
            newHead = cur
            cur = tmp
            count+=1
        head.next = cur
        pre.next = newHead
        return head
    
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        cur = head
        length=0
        while cur!=None:
            length += 1
            cur = cur.next
        term = length/k
        dummy = ListNode(0)
        dummy.next = head
        
        pre = dummy
        for i in range(0, term):
            pre = self.reverseList(pre, k)
        
        return dummy.next


s = Solution()
print(s.mergeKLists([None, None]))
