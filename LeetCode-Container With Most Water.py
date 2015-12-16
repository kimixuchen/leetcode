"""
LeetCode-Container With Most Water
16/12/15 20:58:29
xuchen
"""
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        if length<=1:
            return 0
        l = 0
        r = length-1
        _max = 0
        while l<r:
            _max = max(_max, min(height[l], height[r])*(r-l))
            if height[l]<=height[r]:
                l+=1
            else:
                r-=1
        return _max
        

s = Solution()
tests = []
print(s.maxArea(tests))
tests = [1]
print(s.maxArea(tests))
tests = [1, 2]
print(s.maxArea(tests))
tests = [2, 3, 4, 3]
print(s.maxArea(tests))
