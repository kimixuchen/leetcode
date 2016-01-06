import heapq
"""
LeetCode-23-Merge k Sorted Lists
06/01/16 14:37:23
xuchen
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """ 
        dummy = ListNode(0)
        head = dummy
        h = []
        for i in lists:
            if i:
                heapq.heappush(h, (i.val, i))
        while h:
            cur = heapq.heappop(h)
            dummy.next = cur[1]
            dummy = dummy.next
            if cur[1].next:
                heapq.heappush(h, (cur[1].next.val, cur[1].next))
        
        return head.next
        
s = Solution()
print(s.mergeKLists([None, None]))
