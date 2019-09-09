
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def IsBalanced_Solution(self, pRoot):
        # write code here
        if not pRoot:
            return True
        if abs(self.depth(pRoot.left) - self.depth(pRoot.right)) > 1:
            return False
        
        return self.IsBalanced_Solution(pRoot.left) and self.IsBalanced_Solution(pRoot.right)
    
    def depth(self, root):
        if not root:
            return 0
        left = self.depth(root.left) + 1
        right = self.depth(root.right) + 1
        
        return max(left, right)