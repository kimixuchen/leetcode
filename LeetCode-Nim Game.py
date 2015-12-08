"""
LeetCode-Nim Game
08/12/15 16:12:49
xuchen
"""
class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n%4==0:
            return False
        return True
        
