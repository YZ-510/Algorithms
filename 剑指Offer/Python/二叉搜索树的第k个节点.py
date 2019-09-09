# 中序遍历，输出第 k 个节点

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回对应节点TreeNode
    def KthNode(self, pRoot, k):
        # write code here
        if not pRoot or not k:
            return
        
        res = []
        def traverse(node):
            if len(res) >= k or not node:
                return
            traverse(node.left)
            res.append(node)
            traverse(node.right)
        traverse(pRoot)
        if len(res) < k:
            return
        
        return res[k-1]


class Solution:
    # 返回对应节点TreeNode
    def KthNode(self, pRoot, k):
        # write code here
        self.idx = 0
        self.k = k
        self.target = None
        self.inorder(pRoot)
        return self.target
    
    def inorder(self, root):
        if not root:
            return
        self.inorder(root.left)
        self.idx += 1
        if self.idx == self.k:
            self.target = root
            return self.target
        self.inorder(root.right)