import heapq
"""
LeetCode-26-Remove Duplicates from Sorted Array
10/01/16 20:51:38
xuchen
"""
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length<=0:
            return 0
        pre = nums[0]
        count=1
        for i in range(1, length):
            if nums[i]-pre>0:
                count+=1
                pre = nums[i]
                nums[count-1] = nums[i]
        return count
        
s = Solution()
print(s.removeDuplicates([0,3,4]))
