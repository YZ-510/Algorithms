# 对称二叉树
# https://leetcode-cn.com/problems/symmetric-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # 递归
        
        if not root:
            return True
        return self.symmetric(root.left, root.right)
    
    def symmetric(self, l, r):
        if not l or not r:
            if not l and not r:
                return True
            else:
                return False
        if l.val == r.val:
            return self.symmetric(l.left, r.right) and self.symmetric(l.right, r.left)
        else:
            return False
            
        '''
        # 迭代
        
        if not root:
            return True
        lst = []
        lst.append(root.left)
        lst.append(root.right)
        while lst:
            if lst:
                t1 = lst.pop()
            else:
                t1 = None
            if lst:
                t2 = lst.pop()
            else:
                t2 = None
            if not t1 and not t2:
                continue
            if not t1 or not t2:
                return False
            if t1.val != t2.val:
                return False
            lst.append(t1.left)
            lst.append(t2.right)
            lst.append(t1.right)
            lst.append(t2.left)
        return True     
        '''
