# 填充同一层的兄弟节点 II
# https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/

# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        # 递归
        
        res = []
        self.recurHelper(root, 0, res)
        for cur_level in res:
            for i in range(len(cur_level) - 1):
                cur_level[i].next = cur_level[i + 1]
                
    def recurHelper(self, root, level, res):
        if not root:
            return
        if len(res) < level + 1:
            res.append([])
        res[level].append(root)
        self.recurHelper(root.left, level + 1, res)
        self.recurHelper(root.right, level + 1, res)
        
        '''
        # 迭代
        
        if not root:
            return
        res, cur_level = [], [root]
        while cur_level:
            next_level = []
            for node in cur_level:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            res.append(next_level)
            cur_level = next_level
            
        for cur_level in res:
            for i in range(len(cur_level) - 1):
                cur_level[i].next = cur_level[i + 1]        
        '''