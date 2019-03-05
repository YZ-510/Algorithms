# 钥匙和房间
# https://leetcode-cn.com/problems/keys-and-rooms/

class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        # DFS
        # 把当前门打开，看这个房间的钥匙，找到还没去过的房间，把门打开
        # 依次类推，遍历所有能去到的房间
        # 最后看是否所有的房间都经历过
        
        visited = [0] * len(rooms)
        self.dfs(rooms, 0, visited)
        return sum(visited) == len(rooms)
    
    def dfs(self, rooms, index, visited):
        visited[index] = 1
        for key in rooms[index]:
            if not visited[key]:
                self.dfs(rooms, key, visited)
