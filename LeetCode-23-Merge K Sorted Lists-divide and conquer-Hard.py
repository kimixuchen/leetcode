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
        length = len(lists)
        if length==0:
            return None
        
        if length==1:
            return lists[0]
        
        t = length/2
        return self.mergeTwoLists(self.mergeKLists(lists[0:t]), \
                self.mergeKLists(lists[t:length]))

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
        
s = Solution()
print(s.mergeKLists([None, None]))
