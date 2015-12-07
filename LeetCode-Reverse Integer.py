"""
LeetCode-Reverse Integer
2015-12-07 18:44:37
xuchen
"""

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        retNum = 0
        sign = True
        if x < 0:
            sign = False
            x = -x
        while x > 0:
            retNum = retNum*10 + x%10
            x/=10
        
        if retNum > 0x7fffffff:
            retNum = 0
        if not sign:
            retNum *= -1
        return retNum


s = Solution()
while True:
    t = input()
    print (s.reverse(t))
