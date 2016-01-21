import heapq
"""
LeetCode-29-Divide Two Integers
21/01/16 16:40:26
xuchen
"""
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        m = dividend
        n = divisor
        MAX_INT = 0x7fffffff
        MIN_INT = -0x80000000
        if m > MAX_INT or m < MIN_INT:
            return MAX_INT
        if n > MAX_INT or n < MIN_INT:
            return MAX_INT
        if n == 0:
            return MAX_INT
        if m == MIN_INT and n == -1:
            return MAX_INT
        
        flag = False
        if (m > 0 and n > 0) or (m < 0 and n < 0):
            flag = True
        
        m = abs(m)
        n = abs(n)
        count = 0
        d = 1
        t = n
        while(m!=0):
            if m-t >= 0:
                count += d
                m -= t
                t += t
                d += d
            else:
                if t == n:
                    break
                t = n
                d = 1
        if flag:
            return count
        else:
            return -count
        
s = Solution()
print(s.divide(0, 2))
print(s.divide(1, 1))
print(s.divide(1, 2))
print(s.divide(5, 2))
print(s.divide(-5, -2))
print(s.divide(-0x80000000, -1))
