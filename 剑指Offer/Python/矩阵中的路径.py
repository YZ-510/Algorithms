# 回溯法，在矩阵中任选一个格子作为路径的起点，假设矩阵中某个格子的字符为 ch，并且这个格子将对应与路径上的第 i 个字符。
# 如果路径上的第 i 个字符不是 ch，那么这个格子不可能处于路径上的第 i 个位置；
# 如果路径上的第 i 个字符正好是 ch，那么到相邻的格子寻找路径上的第 i+1 个字符。
# 如果第 n 个字符对应的格子周围都没有找到第 n+1 个字符，在路径上回到第 n-1 个字符，重新定位第 n 个字符。

class Solution:
    def hasPath(self, matrix, rows, cols, path):
        # write code here
        if matrix == None or rows < 1 or cols < 1 or path == None:
            return False
        
        visited = [0] * (rows * cols)
        pathLength = 0
        for row in range(rows):
            for col in range(cols):
                if self.hasPathCore(matrix, rows, cols, row, col, path, pathLength, visited):
                    return True
        
        return False
    
    def hasPathCore(self, matrix, rows, cols, row, col, path, pathLength, visited):
        if len(path) == pathLength:
            return True
        
        hasPath = False
        if row >= 0 and row < rows and col >= 0 and col < cols \
                    and matrix[row * cols + col] == path[pathLength] \
                    and not visited[row * cols + col]:
            pathLength += 1
            visited[row * cols + col] = True
            
            hasPath = self.hasPathCore(matrix, rows, cols, row, col - 1, path, pathLength, visited) or \
                      self.hasPathCore(matrix, rows, cols, row - 1, col, path, pathLength, visited) or \
                      self.hasPathCore(matrix, rows, cols, row, col + 1, path, pathLength, visited) or \
                      self.hasPathCore(matrix, rows, cols, row + 1, col, path, pathLength, visited)
            
            if not hasPath:
                pathLength -= 1
                visited[row * cols + col] = False
            
            return hasPath