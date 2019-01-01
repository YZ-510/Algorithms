# 寻找重复的子树
# https://leetcode-cn.com/problems/find-duplicate-subtrees/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        # 使用先序遍历或后序遍历，保存每个子树的结构在字典中
        # 当下次遇到这个子树的结构时，就把结果放到 res 中
        
        res = []
        m = collections.defaultdict(int)
        self.helper(root, m, res)
        return res
    
    def helper(self, root, m, res):
        if not root:    # 空节点用特殊字符表示，比如 '#'
            return '#'
        path = str(root.val) + ',' + self.helper(root.left, m, res) + ',' + self.helper(root.right, m, res)
        if m[path] == 1:
            res.append(root)
        m[path] += 1
        return path