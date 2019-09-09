# 先遍历两个链表，统计链表长度 m、n，
# 让长的链表先走 |m-n| 步，然后两个链表同步走

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        if pHead1 == None or pHead2 == None:
            return None
        
        pNode1, pNode2 = pHead1, pHead2
        len1 = len2 = 0
        while pNode1 != None:
            len1 += 1
            pNode1 = pNode1.next
        
        while pNode2 != None:
            len2 += 1
            pNode2 = pNode2.next
        
        if len1 > len2:
            while len1 > len2:
                pHead1 = pHead1.next
                len1 -= 1
        else:
            while len1 < len2:
                pHead2 = pHead2.next
                len2 -= 1
        
        while pHead1 and pHead2:
            if pHead1.val == pHead2.val:
                return pHead1
            else:
                pHead1 = pHead1.next
                pHead2 = pHead2.next
        
        return None