# 两个栈，在打印某一行节点时，把下一层的节点保存到相应的栈里。
# 如果当前打印的是奇数层，则先保存左子节点再保存右子节点到第一个栈里；
# 如果当前打印的是偶数层，则先保存右子节点再保存左子节点到第二个栈里。

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def Print(self, pRoot):
        # write code here
        if not pRoot:
            return []
        
        result, nodes = [], [pRoot]
        right = True
        while nodes:
            curStack, nextStack = [], []
            if right:
                for node in nodes:
                    curStack.append(node.val)
                    if node.left:
                        nextStack.append(node.left)
                    if node.right:
                        nextStack.append(node.right)
            else:
                for node in nodes:
                    curStack.append(node.val)
                    if node.right:
                        nextStack.append(node.right)
                    if node.left:
                        nextStack.append(node.left)
            nextStack.reverse()
            right = not right
            result.append(curStack)
            nodes = nextStack
        
        return result


class Solution:
    def Print(self, pRoot):
        # write code here
        if not pRoot:
            return []
        
        stack = [pRoot]
        level = 1
        res = []
        while stack and pRoot:
            temp = [root.val for root in stack]
            if level % 2 == 0:
                res.append(temp[::-1])
            else:
                res.append(temp)
            stack = [kid for root in stack for kid in (root.left, root.right) if kid]
            level += 1
        
        return res