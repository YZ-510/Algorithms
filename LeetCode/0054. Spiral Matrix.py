# 螺旋矩阵
# https://leetcode-cn.com/problems/spiral-matrix/

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        # 四个变量控制边界，方向为：→ ↓ ← ↑
        
        if matrix == []:
            return []
        
        up = left = 0
        down = len(matrix) -1
        right = len(matrix[0]) - 1
        result = []
        
        # 0：→，1：↓，2：←，3：↑
        direction = 0
        while True:
            if direction == 0:
                for i in range(left, right + 1):
                    result.append(matrix[up][i])
                up += 1
            elif direction == 1:
                for i in range(up, down + 1):
                    result.append(matrix[i][right])
                right -= 1
            elif direction == 2:
                for i in reversed(range(left, right + 1)):
                    result.append(matrix[down][i])
                down -= 1
            else:
                for i in reversed(range(up, down + 1)):
                    result.append(matrix[i][left])
                left += 1
            if up > down or left > right:
                return result
            direction = (direction + 1) % 4
            
        
        '''
        if matrix == []:
            return []
        
        left = 0
        up = 0
        down = len(matrix) - 1
        right = len(matrix[0]) - 1
        
        # 0：→，1：↓，2：←，3：↑
        direction = 0
        
        i, j = 0, 0
        result = []

        while True:
            if left > right or up >down:
                return result
            
            if direction == 0:
                while j <= right:
                    result.append(matrix[up][j])
                    j += 1
                up += 1
                i = up
                direction = 1
                continue
                
            if direction == 1:
                while i <= down:
                    result.append(matrix[i][right])
                    i += 1
                right -= 1
                j = right
                direction = 2
                continue
                
            if direction == 2:
                while j >= left:
                    result.append(matrix[down][j])
                    j -= 1
                down -= 1
                i = down
                direction = 3
                continue
                
            if direction == 3:
                while i >= up:
                    result.append(matrix[i][left])
                    i -= 1
                left += 1
                j = left
                direction = 0
                continue
                
        '''
