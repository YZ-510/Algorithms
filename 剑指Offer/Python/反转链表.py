# 需要定义 3 个指针，分别指向当前遍历到的节点、它的前一个节点及后一个节点

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        if pHead == None:
            return None
        
        pReversedHead = None
        pNode = pHead
        pPrev = None
        while pNode != None:
            pNext = pNode.next
            if pNext == None:
                pReversedHead = pNode
            
            pNode.next = pPrev
            pPrev = pNode
            pNode = pNext
        
        return pReversedHead