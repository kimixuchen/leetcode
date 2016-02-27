"""
LeetCode-33-Search in Rotated Sorted Array
27/02/16 09:24:48
xuchen
"""
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        length = len(nums)
        if length < 1:
            return -1
        
        posMax = 0
        if length > 1:
            left = 1
            right = length-1
            while left<=right:
                mid = (left+right)>>1
                if nums[mid] > nums[0]:
                    left = mid+1
                else:
                    right = mid-1
            posMax = left-1
        
        pivot = (posMax+1)%length
        left1 = pivot
        right1 = length-1
        left2 = 0
        right2 = pivot-1
        ans1 = self.BinarySearch(nums, left1, right1, target)
        ans2 = self.BinarySearch(nums, left2, right2, target)
        return max(ans1, ans2)
        
    def BinarySearch(self, nums, left, right, target):
        """
        :type nums: List[int]
        :type left: int
        :type right: int
        :type target: int
        :rtype: int
        """
        pos = -1
        while(left<=right):
            mid = (left+right)>>1
            if nums[mid] > target:
                right = mid-1
            elif nums[mid] < target:
                left = mid+1
            else:
                pos = mid
                break
        return pos

s = Solution()
print s.search([4], 1)
