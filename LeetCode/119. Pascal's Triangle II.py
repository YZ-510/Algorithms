# 杨辉三角 II
# https://leetcode-cn.com/problems/pascals-triangle-ii/

class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        result = [1]
        for i in range(1, rowIndex + 1):
            temp = [1]
            for j in range(1, i):
                temp.append(result[j-1] + result[j])
            temp.append(1)
            result = temp
        return result
        
        '''
        # 递归 超时...
        if rowIndex == 0:
            return [1]
        if rowIndex == 1:
            return [1, 1]
        
        result = [0] * (rowIndex+1)
        result[0] = 1
        result[-1] = 1
        for i in range(1, rowIndex):
            result[i] = self.getRow(rowIndex-1)[i-1] + self.getRow(rowIndex-1)[i]
            
        return result
        '''