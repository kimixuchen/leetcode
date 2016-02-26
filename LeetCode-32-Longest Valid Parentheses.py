"""
LeetCode-32-Longest Valid Parentheses
26/02/16 19:38:48
xuchen
"""

class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        parList = [0]*length
        parentheses = []
        for i in xrange(0, length):
            if s[i]=='(':
                parentheses.append(i)
            else:
                if len(parentheses) <= 0:
                    continue
                else:
                    lPos = parentheses.pop()
                    parList[lPos] = i-lPos+1
        
        preReach = 0
        maxLen = 0
        sumLen = 0
        pos = 0
        while pos < length:
            if parList[pos] > 0:
                sumLen+=parList[pos]
                pos+=parList[pos]
            else:
                sumLen = 0
                pos+=1
            maxLen = max(maxLen, sumLen)
        return maxLen

s = Solution()
pars = ['()(())', '(((())(()))']
for par in pars:
    print (s.longestValidParentheses(par))




