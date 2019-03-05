# 二叉树的最大深度
# https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        left_height = self.maxDepth(root.left)
        right_height = self.maxDepth(root.right)
        return max(left_height, right_height) + 1        
        
        '''
        if not root:
            return 0
        left_height, right_height = 1, 1
        if root.left:
            left_height += self.maxDepth(root.left)
        if root.right:
            right_height += self.maxDepth(root.right)
        if left_height > right_height:
            return left_height
        else:
            return right_height
        '''
