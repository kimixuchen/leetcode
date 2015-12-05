"""
LeetCode-Two Sum-Medium
2015-12-5 09:28:31
xuchen
"""

class Solution(object):

	def __init__(self):
		print(self.twoSum([2,7,11, 15], 9))
		
		
	def twoSum(self, nums, target):
		"""
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
		"""
		rtype=[]
		for i in xrange(0, len(nums)):
			pair = target-nums[i]
			flag=False
			if nums.__contains__(pair):
				for j in xrange(i+1, len(nums)):
					if nums[j]==pair:
						flag=True
						pairpos=j
						break
				if flag:
					rtype.append(i+1)
					rtype.append(j+1)
					break
		
		return rtype
		
s1 = Solution()