# 克隆图
# https://leetcode-cn.com/problems/clone-graph/

# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        
        # DFS
        if not node:
            return
        
        stack = [node]
        res = UndirectedGraphNode(node.label)
        visited = {node.label: res}
        
        while stack:
            cur = stack.pop()
            if cur.label not in visited:
                new_cur = UndirectedGraphNode(cur.label)
                lookup[cur.label] = new_cur
            for neighbor in cur.neighbors:
                if neighbor.label not in visited:
                    new_neighbor = UndirectedGraphNode(neighbor.label)
                    visited[neighbor.label] = new_neighbor
                    stack.append(neighbor)
                visited[cur.label].neighbors.append(visited[neighbor.label])
        return res
        
        '''
        # DFS recursive
        if not node:
            return
        
        def dfs(node):
            if node.label in visited:
                return visited[node.label]
            new_node = UndirectedGraphNode(node.label)
            visited[new_node.label] = new_node
            new_node.neighbors = [dfs(n) for n in node.neighbors]
            return new_node
            
        visited = {}
        return dfs(node)
        '''
