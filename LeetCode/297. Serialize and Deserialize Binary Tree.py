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
            return []
        res, level = [], [root]
        while level:
            for node in level:
                if node:
                    res.append(node.val)
                else:
                    res.append(None)
            temp = []
            for node in level:
                if node:
                    temp.extend([node.left, node.right])
            level = temp
        n = 0
        for i in res[::-1]:
            if i == None:
                n += 1
            else:
                break
        return res[:-n]

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        nodes = [TreeNode(x) if x is not None else None for x in data]
        children = nodes[::-1]
        root = children.pop()
        for node in nodes:
            if node is not None:
                if len(children) > 0:
                    node.left = children.pop()
                if len(children) > 0:
                    node.right = children.pop()
        return root
    
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))