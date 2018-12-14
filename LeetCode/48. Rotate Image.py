# 旋转图像
# https://leetcode-cn.com/problems/rotate-image/

class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        # 先对角线翻转，再中心对称
        
        n = len(matrix)
        for i in range(n-1):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
                
        for i in range(n):
            for j in range(n//2):
                matrix[i][j], matrix[i][n-1-j] = matrix[i][n-1-j], matrix[i][j]
                
        '''
        一次进行4个数字交换：[x][y] -> [n-1-x][y] -> [y][n-1-x] -> [n-1-y][x]
        
        n = len(matrix)
        for i in range(n//2):
            for j in range(n-n//2):
                matrix[i][j], matrix[n-1-j][i], matrix[n-1-i][n-1-j], matrix[j][n-1-i] =\
                matrix[n-1-j][i], matrix[n-1-i][n-1-j], matrix[j][n-1-i], matrix[i][j]

                
        分层翻转，从最外层翻转，一直翻转到最里面一层
        时间复杂度:O(row * col)，空间复杂度：O(1)
        
        def rotateOneLayer(layer):
            n = len(matrix)
            for i in range(layer, n-1-layer):
                matrix[layer][i], matrix[i][n-1-layer], matrix[n-1-layer][n-1-i], matrix[n-1-i][layer] =\
                matrix[n-1-i][layer], matrix[layer][i], matrix[i][n-1-layer], matrix[n-1-layer][n-1-i]
                
        for layer in range((len(matrix)+1)//2):
            rotateOneLayer(layer)
        '''