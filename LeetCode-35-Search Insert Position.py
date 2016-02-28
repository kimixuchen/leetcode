"""
LeetCode-35-Search Insert Position
28/02/16 20:07:40
xuchen
"""
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        length = len(nums)
        l = 0
        r = length-1
        while l<r:
            mid = (l+r)>>1
            if nums[mid] < target:
                l = mid+1
            else:
                r = mid
        if nums[length-1]<target:
            r = length
        return r

s = Solution()
print(s.searchInsert([1, 3, 5, 6], 5))
print(s.searchInsert([1, 3, 5, 6], 2))
print(s.searchInsert([1, 3, 5, 6], 7))
print(s.searchInsert([1, 3, 5, 6], 0))
