"""
LeetCode-22-Generate Parentheses
06/01/16 10:17:57
xuchen
"""
class Solution(object):
    def __init__(self):
        self.cache = [[]]
    
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.cache = [[] for i in range(0, n+1)]
        return self.gen(n)
        
        
    def gen(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if self.cache[n] != []:
            return self.cache[n]
        
        if n==0:
            self.cache[0] = [""]
        else:
            retList = []
            for i in range(0, n):
                lList = self.gen(n-i-1)
                rList = self.gen(i)
                lLength = len(lList)
                rLength = len(rList)
                for j in range(0, lLength):
                    for k in range(0, rLength):
                        newStr = "(" + lList[j] + ")" + rList[k]
                        retList.append(newStr)
            self.cache[n] = retList
        return self.cache[n]

s = Solution()
for i in range(0, 5):
    print(s.generateParenthesis(i))


