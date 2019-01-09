# 二叉搜索树中的插入操作
# https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        # 递归
        
        if not root:
            return TreeNode(val)
        if val < root.val:
            root.left = self.insertIntoBST(root.left, val)
        if val > root.val:
            root.right = self.insertIntoBST(root.right, val)
        return root
        
        '''
        # 迭代
        
        cur = root
        while cur:
            if not cur.left and val < cur.val:
                cur.left = TreeNode(val)
                break
            if not cur.right and val > cur.val:
                cur.right = TreeNode(val)
                break
                
            if cur.val < val:
                cur = cur.right
            else:
                cur = cur.left
        return root        
        '''