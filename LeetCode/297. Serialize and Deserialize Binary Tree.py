# 二叉树的序列化与反序列化
# https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return 'None'
        stack, seriStr = [], ''
        while root or stack:
            while root:
                seriStr += str(root.val) + ','
                stack.append(root)
                root = root.left
            seriStr += 'None,'
            root = stack.pop()
            root = root.right
        seriStr = seriStr[:-1]
        return seriStr

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        serialize = data.split(',')
        tree, sp = self.buildTree(serialize, 0)
        return tree
    
    def buildTree(self, s, sp):
        if sp >= len(s) or s[sp] == 'None':
            return None, sp + 1
        node = TreeNode(int(s[sp]))
        sp += 1
        node.left, sp = self.buildTree(s, sp)
        node.right, sp = self.buildTree(s, sp)
        return node, sp
        
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))