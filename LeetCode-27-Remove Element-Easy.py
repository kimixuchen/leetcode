import heapq
"""
LeetCode-27-Remove Element
11/01/16 19:37:35
xuchen
"""
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        length = len(nums)
        if length==0:
            return 0
        left = 0
        right = length-1
        count=0
        while left<=right:
            if nums[left]==val:
                count+=1
                while right>left:
                    if nums[right]!=val:
                        nums[left] = nums[right]
                        right-=1
                        break
                    else:
                        count+=1
                        right-=1
            left+=1
        return length-count
        
s = Solution()
print(s.removeElement([1,1,2,2,3,3,], 1))
