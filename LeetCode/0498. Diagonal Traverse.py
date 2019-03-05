# 对角线遍历
# https://leetcode-cn.com/problems/diagonal-traverse/

class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if matrix == []:
            return []
        
        m = len(matrix)
        n = len(matrix[0])
        i = 0
        j = 0
        result = []
        
        for k in range(m * n):
            result.append(matrix[i][j])
            # 判断奇偶
            if (i + j) % 2 == 0:
                # 判断边界
                if j == n -1:
                    i += 1
                elif i == 0:
                    j += 1
                else:
                    i -= 1
                    j += 1
            else:
                # 判断边界
                if i == m-1:
                    j += 1
                elif j == 0:
                    i += 1
                else:
                    i += 1
                    j -= 1
                    
        return result
