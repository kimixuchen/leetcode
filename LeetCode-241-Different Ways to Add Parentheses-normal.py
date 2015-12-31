"""
LeetCode-241-Different Ways to Add Parentheses
2015-12-31 17:40:18
xuchen
"""
import string
class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        retList = []
        length = len(input)
        
        lList = []
        rList = []
        hasOperator = False
        for i in range(0, length):
            if input[i] in ['+', '-', '*']:
                hasOperator = True
                lList = self.diffWaysToCompute(input[0:i])
                rList = self.diffWaysToCompute(input[i+1:length])
                for a in lList:
                    for b in rList:
                        if input[i]=='+':
                            retList.append(a+b)
                        elif input[i]=='-':
                            retList.append(a-b)
                        elif input[i]=='*':
                            retList.append(a*b)
        if not hasOperator:
            retList.append(int(input))
        return retList

        
s = Solution()
print(s.diffWaysToCompute("2-1-1"))
print(s.diffWaysToCompute("2*3-4*5"))
