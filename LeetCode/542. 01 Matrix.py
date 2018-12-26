# 01 矩阵
# https://leetcode-cn.com/problems/01-matrix/

class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        # DP 动态规划
        # 分两遍扫描，第一遍扫描左边和上边的元素，第二遍扫描右边和下边的元素
        # 第一遍是横向正向扫描，确保左边和上边的元素已经被扫过
        # 这样每个元素都检查了四个方向，虽然分成两部分，但是这两部分互不干涉
        
        dp = [[float('inf')] * len(matrix[0]) for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                else:
                    if i > 0:
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1)
                    if j > 0:
                        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1)
        for i in reversed(range(len(matrix))):
            for j in reversed(range(len(matrix[i]))):
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                else:
                    if i < len(matrix) - 1:
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1)
                    if j < len(matrix[i]) - 1:
                        dp[i][j] = min(dp[i][j], dp[i][j+1] + 1)
        return dp
        
        '''
        正无穷：float("inf")，负无穷：float("-inf")
        BFS：假如我们把所有的 0 放入一个双端队列（DQ），那么再遍历里面元素相邻的 4 格，然后依此类推即可
        那么最大的问题就是，如何避免重复遍历呢？
        暴力的方法就是进入 DQ 前检查元素是否已经在 DQ 里面了，当然不推荐，因为效率太低
        另一个靠谱一点的方法就是做标记，用一个 flag 矩阵来记录进入 DQ 的元素坐标
        不过如果稍加深入地思考，就会发现其实不用这样
        首先，结果是可以用初始矩阵的，不用重新生成一个，节约空间
        为了避免原来的 1 对后来的结果造成影响
        需要先遍历一遍矩阵，把原来的 1 变成 float('inf')
        第一遍遍历搜 0，第二遍遍历所有与 0 相邻的非 0 元素，它们的距离不可能大于 1
        所有原来的 1 都变成了 float('inf')
        当我们看到某个元素现在是 1 的时候，我们就知道它已经被计算过了
        第三遍遍历的时候 DQ 里面放的就是上一次值为 1 的元素，其相邻元素值可能为 0、1、2（过程中）、float('inf')
        也就是说，在改变了原来的值的情况下，在计算 m[i][j] 相邻元素 x 的时候，假如 x 的值小于或者等于 m[i][j] + 1，x 肯定已经被遍历过了
        简而言之，由于 BFS 与距离的特性，初始化（1 换成无穷大）之后所有非 0 元素只需要一次有效计算就是正确的距离
        换而言之，算过的，不是无穷大的，就是遍历过的了
        
        deque = collections.deque([])
        for i in range(len(matrix)):
            for j in range(len(matrix)):
                if matrix[i][j] == 0:
                    deque.append((i, j))
                else:
                    matrix[i][j] = float('inf')
        
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        while deque:
            e = deque.popleft()
            for d in directions:
                k = tuple(map(operator.add, d, e))
                if not 0 <= k[0] < len(matrix) or not 0 <= k[1] < len(matrix[0]) \
                    or matrix[k[0]][k[1]] <= matrix[e[0]][e[1]] + 1:
                    continue
                else:
                    matrix[k[0]][k[1]] = matrix[e[0]][e[1]] + 1
                    deque.append(k)
        return matrix        
        '''