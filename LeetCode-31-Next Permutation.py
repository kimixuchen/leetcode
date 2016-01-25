import heapq
"""
LeetCode-31-Next Permutation
25/01/16 09:33:16
xuchen
"""
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n<=1:
            return
        pos= 0
        minpos = n-1
        for i in xrange(n-1, 0, -1):
            if nums[i] > nums[i-1]:
                pos = i-1
                minpos = i
                break
        for i in xrange(pos+1, n):
            if nums[i] > nums[pos]:
                if nums[i] < nums[minpos]:
                    minpos = i
        tmp = nums[pos]
        nums[pos] = nums[minpos]
        nums[minpos] = tmp
        left = pos+1
        right = n-1
        while left < right:
            t = nums[left]
            nums[left] = nums[right]
            nums[right] = t
            left += 1
            right -= 1
        for i in xrange(pos+1, n-1):
            if nums[i] > nums[i+1]:
                t = nums[i]
                nums[i] = nums[i+1]
                nums[i+1] = t
        for j in xrange(n-1, pos+1, -1):
            if nums[j] < nums[j-1]:
                t = nums[j]
                nums[j] = nums[j-1]
                nums[j-1] = t
        return
        

s = Solution()
l = [4,5,6,5,4,3]
s.nextPermutation(l)
print(l)
l = [2,1,2,2,2,2,2,1]
s.nextPermutation(l)
print(l)
l = [2,3,1]
s.nextPermutation(l)
print(l)
l = [3,2,1]
s.nextPermutation(l)
print(l)
l = [4,1,4,1,4,3,3,3]
s.nextPermutation(l)
print(l)
