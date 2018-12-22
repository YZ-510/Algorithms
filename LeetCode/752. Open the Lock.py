# 打开转盘锁
# https://leetcode-cn.com/problems/open-the-lock/

class Solution:
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """        
        '''
        典型的 BFS 题目，可以抽象为一个无向图，在图中搜索 target
        BFS 需要一个队列和 visited 集合，visited 保存已经访问过的节点，避免重复访问
        使用 j 来遍历 4 个旋钮，k = -1, 1 表示真向搜索和反向搜索
        '''
        
        deadset = set(deadends)
        if (target in deadset) or ('0000' in deadset):
            return -1
        que = collections.deque()
        que.append('0000')
        visited = set(['0000'])
        step = 0
        while que:
            step += 1
            size = len(que)
            for i in range(size):
                point = que.popleft()
                for j in range(4):
                    for k in range(-1, 2, 2):
                        newPoint = [i for i in point]
                        newPoint[j] = chr((ord(newPoint[j]) - ord('0') + k + 10) % 10 + ord('0'))
                        newPoint = "".join(newPoint)
                        if newPoint == target:
                            return step
                        if (newPoint in deadset) or (newPoint in visited):
                            continue
                        que.append(newPoint)
                        visited.add(newPoint)
        return -1
        
        '''
        que = collections.deque()
        que.append('0000')
        visited = set(deadends)
        step = 0
        while que:
            size = len(que)
            for _ in range(size):
                node = que.popleft()
                if node in visited:
                    continue
                visited.add(node)
                if node == target:
                    return step
                nodelist = list(map(int, list(node)))
                que.append("".join(map(str, [(nodelist[0] + 1 + 10) % 10, nodelist[1], nodelist[2], nodelist[3]])))
                que.append("".join(map(str, [(nodelist[0] - 1 + 10) % 10, nodelist[1], nodelist[2], nodelist[3]])))
                que.append("".join(map(str, [nodelist[0], (nodelist[1] + 1 + 10) % 10, nodelist[2], nodelist[3]])))
                que.append("".join(map(str, [nodelist[0], (nodelist[1] - 1 + 10) % 10, nodelist[2], nodelist[3]])))
                que.append("".join(map(str, [nodelist[0], nodelist[1], (nodelist[2] + 1 + 10) % 10, nodelist[3]])))
                que.append("".join(map(str, [nodelist[0], nodelist[1], (nodelist[2] - 1 + 10) % 10, nodelist[3]])))
                que.append("".join(map(str, [nodelist[0], nodelist[1], nodelist[2], (nodelist[3] + 1 + 10) % 10])))
                que.append("".join(map(str, [nodelist[0], nodelist[1], nodelist[2], (nodelist[3] - 1 + 10) % 10])))
            step += 1
        return -1        
        '''