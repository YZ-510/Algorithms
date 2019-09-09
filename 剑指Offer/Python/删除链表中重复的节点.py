# 头节点也可能被删除，所以在链表头部添加一个节点
# 如果当前节点的值与下一个节点的值相同，那么它们都是重复的节点，需要被删除
# 为了确保删除之后的链表仍然是相连的而没有中间断开，要把当前的前一个节点和与当前节点值不重复的节点相连

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        if pHead == None or pHead.next == None:
            return pHead
        
        first = ListNode(-1)
        first.next = pHead
        prev = first
        while pHead and pHead.next:
            if pHead.val == pHead.next.val:
                val = pHead.val
                while pHead and val == pHead.val:
                    pHead = pHead.next
                prev.next = pHead
            else:
                prev = pHead
                pHead = pHead.next
        
        return first.next


class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        if not pHead:
            return pHead
        
        pl = []
        while pHead:
            pl.append(pHead.val)
            pHead = pHead.next
        npl = []
        for p in pl:
            if pl.count(p) == 1:
                npl.append(p)
        
        head = ListNode(-1)
        h = head
        for p in npl:
            h.next = ListNode(p)
            h = h.next
        
        return head.next