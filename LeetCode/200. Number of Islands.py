# 岛屿的个数
# https://leetcode-cn.com/problems/number-of-islands/

class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if grid is None:
            return None
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        if n == 0:
            return 0
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    res += 1
                    self.dfs(grid, i, j)
        return res
    
    '''
    深度优先搜索
    遍历矩阵的每个元素，如果为 1 ，则计数加 1
    同时把自己和周围元素都置 0
    '''
    
    def dfs(self, grid, i, j):
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
            return 0
        if grid[i][j] == '1':
            grid[i][j] = '0'
            self.dfs(grid, i + 1, j)
            self.dfs(grid, i - 1, j)
            self.dfs(grid, i, j - 1)
            self.dfs(grid, i, j + 1)