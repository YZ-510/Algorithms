# 买卖股票的最佳时机
# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min_price = float('inf')
        max_profit = 0
        for price in prices:
            if price < min_price:
                min_price = price
            elif price - min_price > max_profit:
                max_profit = price - min_price
        return max_profit
        
        '''
        # 对于从第一天后的每一天 i 来说，能赚到的最多的钱是下面两种情况的最大值：
        # 如果在第 i 天卖出，则赚到的钱是第 i-1 天卖出能赚到的钱加上（第 i 天的股价 - 第 i-1 天的股价）
        # 如果在第 i 天不卖出，则赚到的钱为 0
        # 时间复杂度：O(N)，空间复杂度：O(N)
        
        if not prices or len(prices) == 0:
            return 0
        opt = [0] * len(prices)
        for i in range(1, len(prices)):
            opt[i] = max(opt[i-1] + prices[i] - prices[i-1], 0)
        return max(opt)
        
        # 时间复杂度：O(N)，空间复杂度：O(1)
        
        if not prices or len(prices) == 0:
            return 0
        res, max_cur = 0, 0
        for i in range(1, len(prices)):
            max_cur = max(max_cur + prices[i] - prices[i-1], 0)
            res = max(res, max_cur)
        return res
        '''