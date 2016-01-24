import heapq
"""
LeetCode-30-Substring with Concatenation of All Words
24/01/16 14:11:59
xuchen
"""
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        n = len(s)
        k = len(words)
        if n==0 or k==0:
            return 0
        wl = len(words[0])
        ans = []
        wordsDict = {}
        for word in words:
            if wordsDict.__contains__(word):
                wordsDict[word] += 1
            else:
                wordsDict[word] = 1
        
        for i in range(0, wl):
            left = i
            tmpDict = {}
            count = 0
            j = i
            while j <= n-wl:
                subStr = s[j:j+wl]
                if wordsDict.__contains__(subStr):
                    if tmpDict.__contains__(subStr):
                        tmpDict[subStr] += 1
                    else:
                        tmpDict[subStr] = 1
                    count += 1
                    if tmpDict[subStr] > wordsDict[subStr]:
                        while tmpDict[subStr] > wordsDict[subStr]:
                            leftStr = s[left:left+wl]
                            tmpDict[leftStr] -= 1
                            left += wl
                            count -= 1
                    if count == k:
                        tmpDict[s[left:left+wl]] -= 1
                        ans.append(left)
                        left += wl
                        count -= 1
                else:
                    tmpDict.clear()
                    left = j+wl
                    count = 0
                j += wl
        return ans
        

s = Solution()
print(s.findSubstring("barfoothefoobarman",["foo","bar"]))
print(s.findSubstring("aaaaaa",["aa","aa"]))
print(s.findSubstring("",["",""]))

