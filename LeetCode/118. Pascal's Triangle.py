# 杨辉三角
# https://leetcode-cn.com/problems/pascals-triangle/

class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        
        for i in range(numRows):
            if i == 0:
                temp = [1]
            else:
                temp = []
                temp.append(1)
                for j in range(1, i):
                    num = result[i-1][j] + result[i-1][j-1]
                    temp.append(num)
                temp.append(1)
            result.append(temp)
            
        return result