"""
LeetCode-Longest Palindromic Substring
2015-12-06 20:33:33
xuchen
Manacher O(n)
"""

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        ms = "$#"
        for c in s:
            ms += c
            ms += "#"
        ms+='^'
        pos=1
        tail = len(ms)-3
        mx=0
        _maxid=0
        _max=0
        id=0
        p = [0]
        while pos<=tail:
            p.append(1)
            if mx>pos:
                p[pos] = min(p[2*id-pos], mx-pos);
            while ms[pos+p[pos]]==ms[pos-p[pos]]:
                p[pos]+=1

            if p[pos]-1>_max:
                _max = p[pos]-1
                _maxid = pos
            if pos+p[pos]>mx:
                mx = pos+p[pos]
                id=pos
            pos+=1 
        retStr = ""
        retStr = ms[_maxid-_max:_maxid+_max+1]
        retStr = retStr.replace("#", "")
        retStr = retStr.replace("$", "")
        return retStr

s = Solution()
print s.longestPalindrome("abcba")
