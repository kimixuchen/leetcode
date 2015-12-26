"""
LeetCode-Letter Combinations of a Phone Number
26/12/15 10:19:07
xuchen
"""
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        length = len(digits)
        if length == 0:
            return []
        nums = []
        for i in range(0, length):
            nums.append( digit( ord(digits[i])-ord('0') ) )
        
        i = 0
        ans = []
        buffer = ""
        while i >= 0:
            if i>=length:
                ans.append(buffer)
                buffer = buffer[0:i-1]
                i-=1
            else:
                if nums[i].pos<nums[i].lettersLen:
                    buffer += nums[i].letters[nums[i].pos]
                    nums[i].pos+=1
                    i+=1
                else:
                    buffer = buffer[0:i-1]
                    nums[i].pos = 0
                    i-=1
        
        return ans
        
class digit(object):
    def __init__(self, num):
        s = ""
        if num==2:
            s = "abc"
        elif num==3:
            s = "def"
        elif num==4:
            s = "ghi"
        elif num==5:
            s = "jkl"
        elif num==6:
            s = "mno"
        elif num==7:
            s = "pqrs"
        elif num==8:
            s = "tuv"
        elif num==9:
            s = "wxyz"
        elif num==0:
            s = " "
        self.letters = s
        self.lettersLen = len(self.letters)
        self.pos = 0
    
s = Solution()
tests = "2"
print(s.letterCombinations(tests))
tests = ""
print(s.letterCombinations(tests))
tests = "0789"
print(s.letterCombinations(tests))

