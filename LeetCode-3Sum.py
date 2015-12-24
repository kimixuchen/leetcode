"""
LeetCode-3Sum
24/12/15 10:53:25
xuchen
"""
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        length = len(nums)
        if length < 3:
            return []
        nums.sort()
        rList = [[]]
        
        for i in range(0, length-2):
            if i==0 or nums[i]!=nums[i-1]:
                l = i+1
                r = length-1
                b = -nums[i]
                while l < r:
                    if nums[l]+nums[r] < b:
                        l+=1
                    elif nums[l]+nums[r] > b:
                        r-=1
                    else:
                        rList.append([nums[i], nums[l], nums[r]])
                        l+=1
                        while l<length and nums[l]==nums[l-1]:
                            l+=1
                        r-=1
                        while r>i and nums[r]==nums[r+1]:
                            r-=1
        rList.remove([])
        return rList



    
s = Solution()
tests = [-2,-2,-1,-1,0,0,1,1,2,2,3,3]
print(s.threeSum(tests))
tests = [-1, 0, 1, 2, -1, -4]
print(s.threeSum(tests))
tests = [-2,0,1,1,2]
print(s.threeSum(tests))

