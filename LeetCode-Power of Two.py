"""
LeetCode-Power of Two
2015-12-07 21:08:49
xuchen
"""
class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        note = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,
                1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,
                1073741824,2147483648]
        return note.__contains__(n)
s = Solution()
print s.isPowerOfTwo(2)
