"""
LeetCode-20-Valid Parentheses
29/12/15 16:41:51
xuchen
"""
"""
ascii:
    (   40
    )   41
    [   91
    ]   93
    {   123
    }   125
"""
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        symbols = []
        for c in s:
            if c=='(' or c=='{' or c=='[':
                symbols.append(c)
            if c==')' or c=='}' or c==']':
                if len(symbols)==0:
                    return False
                pc = symbols.pop()
                pairsNum = abs(ord(c)-ord(pc))
                if pairsNum!=2 and pairsNum!=1:
                    return False
        
        if len(symbols)!=0:
            return False
       
        return True
        
        
s = Solution()
print(s.removeNthFromEnd(None, 1))

