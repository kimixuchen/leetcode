"""
LeetCode-3Sum Closest
25/12/15 15:58:14
xuchen
"""
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        INF = 0x3f3f3f3f
        length = len(nums)
        nums.sort()
        minGap = INF
        rNum = INF
        
        for i in range(0, length-2):
            preGap = INF
            gap = INF
            l = i+1
            r = length-1
            while l < r:
                sum = nums[i]+nums[l]+nums[r]
                if sum <= target:
                    gap = abs(sum - target)
                    if gap < minGap:
                        minGap = gap
                        rNum = sum
                    preGap = gap
                    l+=1
                elif sum > target:
                    gap = abs(sum - target)
                    if gap < minGap:
                        minGap = gap
                        rNum = sum
                    preGap = gap
                    r-=1
                if rNum==target:
                    return rNum
        return rNum



    
s = Solution()
tests = [-1, 2, 1, -4]
print(s.threeSumClosest(tests, 1))
tests = [-1, 0, 1, 2, -1, -4]
print(s.threeSumClosest(tests, 2))
tests = [-2,0,1,1,2]
print(s.threeSumClosest(tests, 3))

