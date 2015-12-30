"""
LeetCode-122-Best Time to Buy and Sell Stock II
30/12/15 20:31:28
xuchen
"""
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        length = len(prices)
        for i in range(0, length):
            if i+1>=length:
                break
            if prices[i+1]>prices[i]:
                profit += prices[i+1]-prices[i]
        return profit
        
s = Solution()
print(s.maxProfit([1, 2, 4]))

