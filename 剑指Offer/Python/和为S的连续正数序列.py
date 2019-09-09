# 双指针 small=1、big=2，如果从 small 到 big 的序列的和大于 tsum，从序列中去掉较小的值，也就是增大 small；
# 如果从 small 到 big 的序列的和小于 tsum，可以增大 big，让序列包含更多的数字。
# 因为序列至少要有两个数字，一直增加 small 到 (tsum + 1 ) // 2 为止

class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        if tsum < 3:
            return []
        
        small, big, result = 1, 2, []
        middle = (tsum + 1) // 2
        cusm = small + big
        while small < middle:
            if cusm < tsum:
                big += 1
                cusm += big
            elif cusm > tsum:
                cusm -= small
                small += 1
            else:
                result.append([i for i in range(small, big + 1)])
                big += 1
                cusm += big
        
        return result