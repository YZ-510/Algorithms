# 滑动窗口可以看成一个队列，滑动窗口的最大值总是位于队列的头部。
# 双端队列 index，保存有可能是滑动窗口最大值的数字的下标。
# 在存入一个数字的下标之前，首先要判断队列里已有数字是否小于待存入的数字。
# 如果队列里已有的数字小于待存入的数字，那么这些数字已经不可能是滑动窗口的最大值，它们会被依次从队列的尾部删除；
# 如果队列头部的数字已经从窗口里滑出，那么滑出的数字也需要从队列的头部删除。
# 当一个数字的下标与当前处理的数字的下标之差大于或等于滑动窗口的大小时，
# 这个数字已经从窗口中滑出，可以从队列中删除了。

class Solution:
    def maxInWindows(self, num, size):
        # write code here
        if not num or size <= 0:
            return []
        
        res = []
        if len(num) >= size:
            index = []
            for i in range(size): # 先把前 size 个数字存入队列
                while len(index) > 0 and num[i] > num[index[-1]]: # 如果队列里已有数字小于待存入的数字
                    index.pop()
                index.append(i)
            
            for i in range(size, len(num)):
                res.append(num[index[0]])
                while len(index) > 0 and num[i] >= num[index[-1]]: # 如果队列里已有数字小于待存入的数字
                    index.pop()
                if len(index) > 0 and index[0] <= i - size: # 判断队首数字是否已从窗口中滑出
                    index.pop(0)
                index.append(i)
            
            res.append(num[index[0]])
        
        return res


class Solution:
    def maxInWindows(self, num, size):
        # write code here
        if not num or size <= 0:
            return []
        
        if size == len(num):
            return [max(num)]
        res = []
        for i in range(len(num) - size + 1):
            res.append(max(num[i: i + size]))
        
        return res