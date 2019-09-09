# 两个队列，首先把当前层的节点放入队列 1，然后遍历队列 1。
# 遍历时，如果有左子树或右子树，存入队列 2，遍历队列 2。

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        
        nodes, res = [pRoot], []
        while nodes:
            curStack, nextStack = [], []
            for node in nodes:
                curStack.append(node.val)
                if node.left:
                    nextStack.append(node.left)
                if node.right:
                    nextStack.append(node.right)
            res.append(curStack)
            nodes = nextStack
        
        return res


class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        stack = [pRoot]
        res = []
        while pRoot and stack:
            temp = [root.val for root in stack]
            res.append(temp)
            stack = [kid for root in stack for kid in (root.left, root.right) if kid]
        
        return res