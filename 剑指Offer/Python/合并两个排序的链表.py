# 合并时，比较两个链表头节点的大小，小的作为合并后链表的头节点
# 再比较剩余部分和另一个链表的头节点，取小的，一直循环此过程。

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        if pHead1 == None:
            return pHead2
        if pHead2 == None:
            return pHead1
        
        pMergeHead = None
        if pHead1.val < pHead2.val:
            pMergeHead = pHead1
            pMergeHead.next = self.Merge(pHead1.next, pHead2)
        else:
            pMergeHead = pHead2
            pMergeHead.next = self.Merge(pHead1, pHead2.next)
        
        return pMergeHead


# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        if pHead1 == None:
            return pHead2
        if pHead2 == None:
            return pHead1
        
        pMergeHead = ListNode(-1)
        pNode = pMergeHead
        while pHead1 and pHead2:
            if pHead1.val < pHead2.val:
                pNode.next = pHead1
                pHead1 = pHead1.next
            else:
                pNode.next = pHead2
                pHead2 = pHead2.next
            pNode = pNode.next
        
        if pHead1:
            pNode.next = pHead1
        if pHead2:
            pNode.next = pHead2
        
        return pMergeHead.next