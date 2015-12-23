"""
LeetCode-Median of Two Sorted Arrays
23/12/15 14:45:49
xuchen
"""
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1 = len(nums1)
        len2 = len(nums2)
        if len1==0 and len2==0:
            return 0
        if len1>len2:
            A = nums2
            B = nums1
            n = len2
            m = len1
        else:
            A = nums1
            B = nums2
            n = len1
            m = len2
        half = (len1+len2+1)/2
        mini = 0
        maxi = n
        while mini<=maxi:
            i = (mini+maxi)/2
            j = half-i
            if i>0 and j<m and B[j]<A[i-1]:
                maxi = i-1
            elif i<n and j>0 and A[i]<B[j-1]:
                mini = i+1
            else:
                break
        
        num1 = 0
        num2 = 0
        if i==0:
            num1 = B[j-1]
        elif j==0:
            num1 = A[i-1]
        else:
            num1 = max(A[i-1], B[j-1])
        
        if (n+m)%2==1:
            return num1
        
        if i==n:
            num2 = B[j]
        elif j==m:
            num2 = A[i]
        else:
            num2 = min(A[i], B[j])
        
        ans = (num1+num2)*1.0/2
        return ans
        
s = Solution()
tests = [[], [1]]
print(s.findMedianSortedArrays([], [1]))
tests = [[1], []]
print(s.findMedianSortedArrays([1], []))
tests = [[], []]
print(s.findMedianSortedArrays([], []))
tests = [[1], [1]]
print(s.findMedianSortedArrays([1], [1]))
tests = [[1], [2,3,4,5]]
print(s.findMedianSortedArrays([1], [2,3,4,5]))
tests = [[], [1,2,3]]
print(s.findMedianSortedArrays([], [1,2,3]))
