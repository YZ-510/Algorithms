# 前序遍历的第一个值一定为根节点，在中序遍历中该点左侧的值为根节点的左子树，右侧的值为根节点的右子树
# 利用递归，取前序遍历的 [1:i+1] 和中序遍历的 [:i] 作为对应的左子树继续上一个过程
# 取前序遍历的 [i+1:] 和中序遍历的 [i+1:] 作为对应的右子树继续上一个过程

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        if not pre and not tin:
            return None
        if set(pre) != set(tin):
            return None
        
        root = TreeNode(pre[0])
        i = tin.index(pre[0])
        root.left = self.reConstructBinaryTree(pre[1:i+1], tin[:i])
        root.right = self.reConstructBinaryTree(pre[i+1:], tin[i+1:])
        
        return root