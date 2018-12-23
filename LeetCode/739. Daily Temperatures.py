# 每日温度
# https://leetcode-cn.com/problems/daily-temperatures/

class Solution:
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        # 时间复杂度：O(N)，空间复杂度：O(W)
        
        res = [0] * len(T)
        stack = []  # 存储天数的 index
        for i in range(len(T) - 1, -1, -1):
            while stack and T[i] >= T[stack[-1]]:
                stack.pop()
            if stack:
                res[i] = stack[-1] - i  # 第一个 warmer 天的 index 与当前天数 index 的差值
            stack.append(i)
        return res