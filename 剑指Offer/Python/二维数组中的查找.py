# 从右上开始查找，如果数组中的数比这个整数小，往左移动一位；否则向下移动一位

class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        if array == []:
            return False
        row = len(array)
        col = len(array[0])
        
        i = row - 1
        j = 0
        while i >= 0 and j < col:
            if array[i][j] > target:
                i -= 1
            elif array[i][j] < target:
                j += 1
            else:
                return True
        
        return False