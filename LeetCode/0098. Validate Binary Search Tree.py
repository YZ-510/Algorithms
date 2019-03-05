# 验证二叉搜索树
# https://leetcode-cn.com/problems/validate-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # 中序遍历，看列表 res 是否满足递增
        
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            res.append(root)
            inorder(root.right)
            
        res = []
        if not root:
            return True
        inorder(root)
        for i in range(1, len(res)):
            if res[i].val <= res[i-1].val:
                return False
        return True
