# 最大堆、最小堆，分别存储比中位数小的数和大的数
# 当两个堆的总数为偶数时，把数字存入最大堆，然后重排最大堆。
# 如果最大堆堆顶的数字大于最小堆堆顶的数字，则交换，然后重排两个堆。
# 此时两个堆总数为奇数，输出最大堆堆顶的数字。
# 当两个堆的总数为奇数时，把数字存入最小堆，重排最小堆。
# 如果最大堆堆顶的数字大于最小堆堆顶的数字，则交换，重排两个堆。
# 此时两个堆总数为偶数，输出两堆堆顶的数字的平均值。

class Solution:
    def __init__(self):
        self.left = []
        self.right = []
        self.count = 0
    
    def Insert(self, num):
        # write code here
        if self.count & 1 == 0:
            self.left.append(num)
        else:
            self.right.append(num)
        self.count += 1
    
    def GetMedian(self, x):
        # write code here
        if self.count == 1:
            return self.left[0]
        
        self.MaxHeap(self.left)
        self.MinHeap(self.right)
        
        if self.left[0] > self.right[0]:
            self.left[0], self.right[0] = self.right[0], self.left[0]
        self.MaxHeap(self.left)
        self.MinHeap(self.right)
        
        if self.count & 1 == 0:
            return (self.left[0] + self.right[0]) / 2.0
        else:
            return self.left[0]
    
    def MaxHeap(self, alist):
        length = len(alist)
        if alist == None or length <= 0:
            return
        if length == 1:
            return alist
        for i in range(length // 2 - 1, -1, -1):
            k = i
            temp = alist[k]
            heap = False
            while not heap and 2 * k < length - 1:
                index = 2 * k + 1
                if index < length - 1:
                    if alist[index] < alist[index + 1]:
                        index += 1
                if temp >= alist[index]:
                    heap = True
                else:
                    alist[k] = alist[index]
                    k = index
            alist[k] = temp
    
    def MinHeap(self, alist):
        length = len(alist)
        if alist == None or length <= 0:
            return
        if length == 1:
            return alist
        for i in range(length // 2 - 1, -1, -1):
            k = i
            temp = alist[k]
            heap = False
            while not heap and 2 * k < length - 1:
                index = 2 * k + 1
                if index < length - 1:
                    if alist[index] > alist[index + 1]:
                        index += 1
                if temp <= alist[index]:
                    heap = True
                else:
                    alist[k] = alist[index]
                    k = index
            alist[k] = temp


class Solution:
    def __init__(self):
        self.stack = []
    
    def Insert(self, num):
        # write code here
        self.stack.append(num)
        self.stack.sort()
    
    def GetMedian(self, stack):
        # write code here
        n = len(self.stack)
        if n % 2 != 0:
            return self.stack[int(n/2)]
        else:
            return (self.stack[int(n/2) - 1] + self.stack[int(n/2)]) / 2.0