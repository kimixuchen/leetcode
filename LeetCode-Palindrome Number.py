"""
LeetCode-Palindrome Number
10/12/15 21:09:00
xuchen
"""
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        if x==0:
            return True
        y=0
        while y<x:
            y = y*10 +x%10
            if y==0:
                return False
            if y==x:
                return True
            x/=10
            if y==x:
                return True
        
        return False

s = Solution()
print(s.isPalindrome(1455541))
