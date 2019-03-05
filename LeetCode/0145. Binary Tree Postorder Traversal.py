# 二叉树的后序遍历
# https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # 递归
        
        if not root:
            return []
        res = []
        if root.left:
            res.extend(self.postorderTraversal(root.left))
        if root.right:
            res.extend(self.postorderTraversal(root.right))
        res.append(root.val)
        return res
        
        '''
        if not root:
            return []
        res = []
        self.postorder(root, res)
        return res
    
    def postorder(self, root, res):
        if not root:
            return
        self.postorder(root.left, res)
        self.postorder(root.right, res)
        res.append(root.val)        
        '''
        
        '''
        # 迭代，后序遍历是左右中，先按照中右左的顺序放入列表，再反转列表即可
        
        if not root:
            return []
        res, stack = [], [root]
        node = root
        while stack:
            node = stack.pop()
            res.append(node.val)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return res[::-1]        
        '''
