
"""
LeetCode-Longest Substring Without Repeating Characters-Medium
2015-12-6 15:20:30
xuchen
"""

class Solution(object):

	def lengthOfLongestSubstring(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		length=len(s)
		charsDic = {}
		charsDic.clear()
		start=0
		end=0
		_max=0
		while end<length:
			if not charsDic.__contains__(s[end]):
				charsDic[s[end]] = end
				end+=1
			else:
				if end-start > _max:
					_max = end-start
				start = charsDic[s[end]]+1
				charsDic.clear()
				for i in range(start, end+1):
					charsDic[s[i]] = i
				end+=1
		
		if end-start > _max:
			_max = end-start
		
		return _max

s = Solution()
print(s.lengthOfLongestSubstring("acvdf"))

"""
 * Solution (DP, O(n)):
 * 
 * Assume L[i] = s[m...i], denotes the longest substring without repeating
 * characters that ends up at s[i], and we keep a hashmap for every
 * characters between m ... i, while storing <character, index> in the
 * hashmap.
 * We know that each character will appear only once.
 * Then to find s[i+1]:
 * 1) if s[i+1] does not appear in hashmap
 *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *    entry in hashmap to mark the latest occurency of s[i+1].
 * 
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 *
 * If characters are all in ASCII, we could use array to mimic hashmap.
"""
