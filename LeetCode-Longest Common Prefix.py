"""
LeetCode-Longest Common Prefix
22/12/15 16:19:36
xuchen
"""
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        retStr = ""
        n = len(strs)
        if n==0:
            return ""
        minpos = len(strs[0])
        for i in range(1, n):
            pos = 0
            while  pos < len(strs[i]) and pos < len(strs[0]) and \
                    strs[i].__getitem__(pos)==strs[0].__getitem__(pos):
                pos+=1
                if pos >= minpos:
                    break;
            minpos = min(minpos, pos)
        
        if minpos==0:
            return ""
        else:
            return strs[0].__getslice__(0, minpos)

s = Solution()
tests = ["c", "acc", "ccc"]
print(s.longestCommonPrefix(tests))
tests = ["123", "1"]
print(s.longestCommonPrefix(tests))
tests = ["12345", "123"]
print(s.longestCommonPrefix(tests))
