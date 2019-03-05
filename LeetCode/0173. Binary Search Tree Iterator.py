# 二叉搜索树迭代器
# https://leetcode-cn.com/problems/binary-search-tree-iterator/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 先从 root 遍历左子树，把所有左子节点放入 stack，然后取 cur
# 如果 cur 有右子节点，把 cur 右子节点的所有左子节点放入 stack

class BSTIterator(object):
    
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.root = root
        self.stack = []
        self.pushAllLeft(root)

    def next(self):
        """
        @return the next smallest number
        :rtype: int
        """
        if self.hasNext():
            cur = self.stack.pop()
            if cur.right:
                self.pushAllLeft(cur.right)
            return cur.val

    def hasNext(self):
        """
        @return whether we have a next smallest number
        :rtype: bool
        """
        return self.stack != []
    
    def pushAllLeft(self, node):
        cur = node
        while cur:
            self.stack.append(cur)
            cur = cur.left

    '''
    # 中序遍历，得到有序排列
    
class BSTIterator(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.root = root
        self.lst = []
        self.inOrder(root)
        self.lst.reverse()

    def next(self):
        """
        @return the next smallest number
        :rtype: int
        """
        return self.lst.pop()

    def hasNext(self):
        """
        @return whether we have a next smallest number
        :rtype: bool
        """
        return self.lst != []
    
    def inOrder(self, root):
        if root == None:
            return
        self.inOrder(root.left)
        self.lst.append(root.val)
        self.inOrder(root.right)
    '''

# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
