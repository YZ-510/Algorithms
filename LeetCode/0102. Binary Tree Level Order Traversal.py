# 二叉树的层次遍历
# https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        # 递归
        
        def dfs(node, level, res):
            if not node:
                return
            if len(res) < level:
                res.append([])
            res[level - 1].append(node.val)
            dfs(node.left, level + 1, res)
            dfs(node.right, level + 1, res)
            
        res = []
        dfs(root, 1, res)
        return res
        
        '''
        # 迭代，cur_level 和 next_level 记录每层节点
        
        if not root:
            return []
        res, cur_level = [], [root]
        while cur_level:
            next_level, tmp_res = [], []
            for node in cur_level:
                tmp_res.append(node.val)
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            res.append(tmp_res)
            cur_level = next_level
        return res        
        '''
