# 二叉树的序列化：前序遍历二叉树输出节点，遇到左子节点和右子节点为 None 的时候，输出一个特殊字符
# 反序列化：针对前序遍历，可以先设置一个指针，指向序列的开头，然后把指针位置的数字转化为节点，
# 当遇到特殊字符时或者超出序列长度时，对应节点为 None，然后继续遍历。

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def __init__(self):
        self.flag = -1
    
    def Serialize(self, root):
        # write code here
        if not root:
            return '#,'
        
        return str(root.val) + ',' + self.Serialize(root.left) + self.Serialize(root.right)
    
    def Deserialize(self, s):
        # write code here
        self.flag += 1
        l = s.split(',')
        
        if self.flag >= len(s):
            return None
        root = None
        
        if l[self.flag] != '#':
            root = TreeNode(int(l[self.flag]))
            root.left = self.Deserialize(s)
            root.right = self.Deserialize(s)
        
        return root