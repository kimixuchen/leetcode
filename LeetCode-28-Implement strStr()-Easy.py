import heapq
"""
LeetCode-28-Implement strStr()
17/01/16 16:05:57
xuchen
"""
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle=="":
            return 0
        lh = len(haystack)
        ln = len(needle)
        for i in range(0, lh-ln+1):
            count = 0
            for j in range(0, ln):
                if(haystack[i+j]==needle[j]):
                    count+=1
                else:
                    break
            if count==ln:
                return i
        return -1
        
