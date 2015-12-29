"""
LeetCode-19-Remove Nth Node From End of List
29/12/15 16:33:07
xuchen
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        cur = head
        preN = head
        count = 0
        while cur!=None:
            cur = cur.next
            count+=1
            if count > n+1:
                preN = preN.next
        if count<=n:
            head = head.next
        else:
            preN.next = preN.next.next
        
        return head
        
s = Solution()
print(s.removeNthFromEnd(None, 1))

