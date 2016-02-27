"""
LeetCode-34-Search for a Range
27/02/16 10:15:17
xuchen
"""
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        lPos = -1
        rPos = -1
        left = 0
        right = length-1
        while left <= right:
            mid = (left+right)>>1
            if nums[mid]<target:
                left = mid+1
            elif nums[mid]>target:
                right = mid-1
            else:
                lPos = mid
                right = mid-1
        left = 0
        right = length-1
        while left <= right:
            mid = (left+right)>>1
            if nums[mid]<target:
                left = mid+1
            elif nums[mid]>target:
                right = mid-1
            else:
                rPos = mid
                left = mid+1
        
        return [lPos, rPos]
s = Solution()
print s.searchRange([2, 2], 2)
