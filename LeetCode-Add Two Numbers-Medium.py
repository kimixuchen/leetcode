"""
LeetCode-Add Two Numbers-Medium
2015-12-05 20:52:32
xuchen
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
	def addTwoNumbers(self, l1, l2):
		"""
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
		head = ListNode(0)
		tmpNode = head
		carry=0
		_sum=0
		while l1!=None and l2!=None:
			_sum = l1.val+l2.val+carry
			carry = _sum/10
			_sum %= 10
			newNode = ListNode(int(_sum))
			tmpNode.next = newNode
			tmpNode = newNode
			l1 = l1.next
			l2 = l2.next
		
		while l1!=None:
			_sum = l1.val+carry
			carry = _sum/10
			_sum %= 10
			newNode = ListNode(int(_sum))
			tmpNode.next = newNode
			tmpNode = newNode
			l1 = l1.next

		while l2!=None:
			_sum = l2.val+carry
			carry = _sum/10
			_sum %= 10
			newNode = ListNode(int(_sum))
			tmpNode.next = newNode
			tmpNode = newNode
			l2 = l2.next
		
		if int(carry) > 0:
			newNode = ListNode(carry)
			tmpNode.next = newNode
			tmpNode = newNode
		
		head = head.next
		return head

			



s = Solution()
l1 = ListNode(2)
l2 = ListNode(4)
l3 = ListNode(3)
l1.next = l2
l2.next = l3
l4 = ListNode(5)
l5 = ListNode(6)
l4.next = l5

answer = s.addTwoNumbers(l1,l4)
while answer!=None:
	print("%d " % answer.val)
	answer = answer.next
