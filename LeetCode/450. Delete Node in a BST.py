# 删除二叉搜索树中的节点
# https://leetcode-cn.com/problems/delete-node-in-a-bst/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        def findmin(root):
            while root.left:
                root = root.left
            return root
        
        # 递归找到该节点
        if not root:
            return None
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if root.left and root.right:    # 该节点左右子节点均存在
                tmp = findmin(root.right)   # 寻找该节点右子树中的最小值来替换
                root.val = tmp.val
                root.right = self.deleteNode(root.right, tmp.val)   # 删除这一最小值节点
            else:
                if not root.left:   # 该节点只有右子节点
                    root = root.right
                else:                   
                    root = root.left
        return root