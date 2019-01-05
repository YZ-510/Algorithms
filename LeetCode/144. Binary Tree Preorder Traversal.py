# 二叉树的前序遍历
# https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # 递归
        
        res = []
        if not root:
            return res
        res.append(root.val)
        if root.left:
            res.extend(self.preorderTraversal(root.left))
        if root.right:
            res.extend(self.preorderTraversal(root.right))
        return res
        
        '''
        if not root:
            return []
        res = []
        self.preorder(root, res)
        return res
    
    def preorder(self, root, res):
        if not root:
            return
        res.append(root.val)
        self.preorder(root.left, res)
        self.preorder(root.right, res)        
        '''
        
        '''
        # 迭代
        if not root:
            return []
        res, stack = [], [root]
        while stack:
            node = stack.pop()
            res.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return res        
        '''