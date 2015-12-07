"""
LeetCode-ZigZag Conversion
2015-12-07 16:44:19
xuchen
"""

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows==1:
            return s
        retS = ""
        interval = numRows*2-2
        for i in range(0, numRows):
            pos = i
            offset = interval-i*2
            while pos<len(s):
                if offset != 0:
                    retS += s[pos]
                    pos += offset
                offset = interval-offset
        return retS

s = Solution()
while True:
    t = raw_input()
    num = raw_input()
    num = int(num)
    print s.convert(t, num)
