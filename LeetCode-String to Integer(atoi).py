"""
LeetCode-String to Integer(atoi)
13/12/15 15:30:05
xuchen
"""
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        INT_MAX = 0x7fffffff
        INT_MIN = -0x80000000
        retNum=0
        pos=0
        signal = 1
        length = len(str)
        while pos<length and str[pos]==' ':
            pos+=1
        
        while pos<length:
            if str[pos]=='-':
                if(pos+1>=length):
                    retNum=0
                    break
                if ord(str[pos+1])<ord('0') or ord(str[pos+1])>ord('9'):
                    retNum=0
                    break
                signal = -1
            elif str[pos]=='+':
                if(pos+1>=length):
                    retNum=0
                    break
                if ord(str[pos+1])<ord('0') or ord(str[pos+1])>ord('9'):
                    retNum=0
                    break
                signal = 1
            elif ord(str[pos])<ord('0') or ord(str[pos])>ord('9'):
                break
            else:
                retNum*=10
                retNum+=ord(str[pos])-ord('0')
            pos+=1
            
        retNum*=signal
        if retNum>INT_MAX:
            retNum = INT_MAX
        if retNum<INT_MIN:
            retNum = INT_MIN
        return retNum

s = Solution()
tests = ['123', '-5', '0021', '  23', '256sd ', '2 3', '+-2', '2147483648', '-2147483649']
for num in tests:
    print(num)
    print s.myAtoi(num)
