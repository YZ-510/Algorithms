# -*- coding:utf-8 -*-
class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        if not matrix:
            return []
        rows = len(matrix)
        columns = len(matrix[0])
        start = 0
        result = []
        while rows > start * 2 and columns > start * 2:
            self.PrintMartixInCircle(matrix, columns, rows, start, result)
            start += 1
        
        return result
    
    def PrintMartixInCircle(self, matrix, columns, rows, start, result):
        endX = columns - 1 - start
        endY = rows - 1 - start
        
        # 从左到右打印一行
        for i in range(start, endX + 1):
            result.append(matrix[start][i])
        
        # 从上到下打印一行
        if start < endY:
            for i in range(start + 1, endY + 1):
                result.append(matrix[i][endX])
        
        # 从右到左打印一行
        if start < endX and start < endY:
            for i in range(endX - 1, start - 1, -1):
                result.append(matrix[endY][i])
        
        # 从下到上打印一行
        if start < endX and start < endY - 1:
            for i in range(endY - 1, start, -1):
                result.append(matrix[i][start])