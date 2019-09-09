# 前序遍历二叉树的节点，如果该节点是叶节点，且路径中节点值的和等于输入整数，则当前路径符合要求；
# 如果不是叶节点，则继续访问它的子节点，直到访问到符合要求的叶节点

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        if not root or root.val > expectNumber:
            return []
        
        if not root.left and not root.right and root.val == expectNumber:
            return [[root.val]]
        else:
            expectNumber -= root.val
            left = self.FindPath(root.left, expectNumber)
            right = self.FindPath(root.right, expectNumber)
            
            result = [[root.val] + i for i in left]
            for i in right:
                result.append([root.val] + i)
        
        return sorted(result, key=lambda x:-len(x))