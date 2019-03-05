# 图像渲染
# https://leetcode-cn.com/problems/flood-fill/

class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        # BFS，100 ms
        row = len(image)
        col = len(image[0])
        tmp = image[sr][sc]
        queue = []
        visited = []
        queue.append([sr, sc])
        while queue:
            x, y = queue[0][0], queue[0][1]
            if image[x][y] == tmp:
                image[x][y] = newColor
            if 0 <= y+1 < col and [x, y+1] not in visited:
                if image[x][y+1] == tmp:
                    queue.append([x, y+1])
            if 0 <= y-1 < col and [x, y-1] not in visited:
                if image[x][y-1] == tmp:
                    queue.append([x, y-1])
            if 0 <= x+1 < row and [x+1, y] not in visited:
                if image[x+1][y] == tmp:
                    queue.append([x+1, y])
            if 0 <= x-1 < row and [x-1, y] not in visited:
                if image[x-1][y] == tmp:
                    queue.append([x-1, y])
            visited.append(queue.pop(0))
                
        return image
        
        '''
        # DFS，时间复杂度：O(N^2)，空间复杂度：O(N^2), 68 ms
        
        row = len(image)
        col = len(image[0])
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        
        def dfs(image, sr, sc, color):
            stack, visited = [[sr, sc]], []
            while stack:
                vertex = stack.pop()
                if vertex not in visited:
                    visited.append(vertex)
                    x, y = vertex[0], vertex[1]
                    for m, n in [x-1, y], [x+1, y], [x, y-1], [x, y+1]:
                        if 0 <= m < row and 0 <= n <col:
                            if [m, n] not in visited:
                                if image[m][n] == color:
                                    stack.append([m, n])
            return visited
        
        for i in dfs(image, sr, sc, image[sr][sc]):
            image[i[0]][i[1]] = newColor
            
        return image        
        '''
