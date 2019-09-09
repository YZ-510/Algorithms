# 回溯法，把方格看成一个 m*n 的矩阵，从（0，0）开始移动，当准备进入坐标（i，j）时，
# 通过检查坐标的数位和来判断机器人是否能够进入，如果能够进入，再判断它能否进入四个相邻的格子。

class Solution:
    def movingCount(self, threshold, rows, cols):
        # write code here
        visited = [False] * (rows * cols)
        count = self.movingCountCore(threshold, rows, cols, 0, 0, visited)
        
        return count
    
    def movingCountCore(self, threshold, rows, cols, row, col, visited):
        count = 0
        if self.check(threshold, rows, cols, row, col, visited):
            visited[row * cols + col] = True
            count = 1 + self.movingCountCore(threshold, rows, cols, row - 1, col, visited) + \
                        self.movingCountCore(threshold, rows, cols, row + 1, col, visited) + \
                        self.movingCountCore(threshold, rows, cols, row, col - 1, visited) + \
                        self.movingCountCore(threshold, rows, cols, row, col + 1, visited)
        
        return count
    
    def check(self, threshold, rows, cols, row, col, visited):
        if row >= 0 and row < rows and col >= 0 and col < cols \
                    and self.getDigitSum(row) + self.getDigitSum(col) <= threshold \
                    and not visited[row * cols + col]:
            return True
        return False
    
    def getDigitSum(self, number):
        sum = 0
        while number > 0:
            sum += (number % 10)
            number = number // 10
        
        return sum