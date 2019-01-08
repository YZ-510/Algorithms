# 二叉树的最近公共祖先
# https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        # 寻找从 root 分别到节点 p、q 的路径
        def findPath(root, path, node):
            if not root:
                return False
            path.append(root)
            if root == node:
                return True
            if (root.left and findPath(root.left, path, node)) or (root.right and findPath(root.right, path, node)):
                return True
            path.pop()
            return False
        
        path_p, path_q = [], []
        if not findPath(root, path_p, p) or not findPath(root, path_q, q):
            return -1
        i = 0
        while i < len(path_p) and i < len(path_q):  # 遍历两个路径，返回元素值不相等的前一个公共元素
            if path_p[i] != path_q[i]:
                break
            i += 1
        return path_p[i - 1]
        
        '''
        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            if (p.val == left.val and q.val == right.val) or (p.val == right.val and q.val == left.val):
                return root
        return left or right        
        '''