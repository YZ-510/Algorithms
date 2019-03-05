# 二叉树的中序遍历
# https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # 递归
        
        res = []
        if not root:
            return res
        if root.left:
            res.extend(self.inorderTraversal(root.left))
        res.append(root.val)
        if root.right:
            res.extend(self.inorderTraversal(root.right))
        return res
        
        '''
        # 迭代
        # 先走到最左边、node 入栈，此时 node 为 None
        # 然后 node 出栈，出栈的每个 node 都是自己这棵树的 root
        # 判断是否有右子节点
        
        res = []
        if not root:
            return res
        
        stack = []
        node = root
        while node or len(stack) > 0:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                res.append(node.val)
                node = node.right
        return res        
        '''
        
        '''
        if root == None:
            return []
        res = []
        self.inorder(root, res)
        return res
    
    def inorder(self, root, res):
        if root == None:
            return
        self.inorder(root.left, res)
        res.append(root.val)
        self.inorder(root.right, res)        
        '''
