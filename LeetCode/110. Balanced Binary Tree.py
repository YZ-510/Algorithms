# 平衡二叉树
# https://leetcode-cn.com/problems/balanced-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def height(node):
            if not node:
                return 0
            left = height(node.left)
            right = height(node.right)
            if left == -1 or right == -1 or abs(left - right) > 1:
                return -1
            return max(left, right) + 1
        
        return height(root) != -1        
        
        '''
        def height(node):
            if not node:
                return 0
            return 1 + max(height(node.left), height(node.right))
        
        if not root:
            return True
        return abs(height(root.left) - height(root.right)) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)
        '''