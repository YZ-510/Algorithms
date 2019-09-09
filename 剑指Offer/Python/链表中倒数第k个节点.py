# 双指针，第一个指针向前走 k-1 步，走到第 k 个节点，第二个指针和第一个指针同时移动，
# 当第一个指针到达尾节点的时候，第二个指针指向倒数第 k 个节点。

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head == None or k <= 0:
            return None
        
        pAhead = head
        pBhead = None
        for i in range(k - 1):
            if pAhead.next != None:
                pAhead = pAhead.next
            else: # k 大于链表长度
                return None
        
        pBhead = head
        while pAhead.next != None:
            pAhead = pAhead.next
            pBhead = pBhead.next
        
        return pBhead