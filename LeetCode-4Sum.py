"""
LeetCode-4Sum
29/12/15 11:50:21
xuchen
"""
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        length = len(nums)
        if length < 4:
            return []
        nums.sort()
        rList = []
        
        for i in range(0, length-3):
            if i==0 or nums[i]!=nums[i-1]:
                if target < nums[i]<<2:
                    break
                for j in range(i+1, length-2):
                    if j==i+1 or nums[j]!=nums[j-1]:
                        if target < (nums[i]+nums[j])<<1:
                            break
                        l = j+1
                        r = length-1
                        b = target-nums[i]-nums[j]
                        while l < r:
                            if nums[l]+nums[r] < b:
                                l+=1
                            elif nums[l]+nums[r] > b:
                                r-=1
                            else:
                                rList.append([nums[i], nums[j], nums[l], nums[r]])
                                l+=1
                                while l<length and nums[l]==nums[l-1]:
                                    l+=1
                                r-=1
                                while r>j and nums[r]==nums[r+1]:
                                    r-=1
        return rList


    
s = Solution()
tests = [1, 0, -1, 0, -2, 2]
print(s.fourSum(tests, 0))

