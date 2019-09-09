# 三种情况：当前节点有右子树，当前节点的下一个节点是右子树的最左子节点；
# 当前节点无右子树但它是父节点的左子节点，下一个节点就是当前节点的父节点；
# 当前节点无右子树而且是父节点的右子节点，则一直向上遍历，
# 直到找到一个是它父节点的左子节点的节点，如果这样的节点存在，这个节点的父节点就是要找的下一个节点

# -*- coding:utf-8 -*-
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None
class Solution:
    def GetNext(self, pNode):
        # write code here
        if pNode == None:
            return None
        
        pNext = None
        if pNode.right:
            pNode = pNode.right
            while pNode.left:
                pNode = pNode.left
            pNext = pNode
        else:
            if pNode.next and pNode.next.left == pNode:
                pNext = pNode.next
            elif pNode.next and pNode.next.right == pNode:
                pNode = pNode.next
                while pNode.next and pNode.next.right == pNode:
                    pNode = pNode.next
                # 遍历终止时当前节点有父节点，说明当前节点是父节点的左子节点，输入节点的下一个节点为当前节点的父节点
                # 反之终止时当前节点没有父节点，说明当前节点位于根节点的右子树，没有下一个节点
                if pNode.next:
                    pNext = pNode.next
        
        return pNext


# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None
class Solution:
    def GetNext(self, pNode):
        # write code here
        if not pNode:
            return None
        
        if pNode.right:
            pr = pNode.right
            while pr.left:
                pr = pr.left
            return pr
        while pNode.next:
            pp = pNode.next
            if pp.left == pNode:
                return pp
            pNode = pp