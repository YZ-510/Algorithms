# 相交链表
# https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """        
        '''
        计算出两个链表的长度差，长链表先走（len_A - len_B）步
        然后两个链表一起走，若节点相同则为第一个相交点
        '''
        
        len_A = 0
        len_B = 0
        pA = headA
        pB = headB
        while pA:
            len_A += 1
            pA = pA.next
            
        while pB:
            len_B += 1
            pB = pB.next
            
        if len_A > len_B:
            while len_A > len_B:
                headA = headA.next
                len_A -= 1
            while headA != headB and headA and headB:
                headA = headA.next
                headB = headB.next
            return headA
        else:
            while len_A < len_B:
                headB = headB.next
                len_B -= 1
            while headA != headB and headA and headB:
                headA = headA.next
                headB = headB.next
            return headB
        
        '''
        pA, pB = headA, headB
        while pA is not pB:
            pA = pA.next if pA else headB
            pB = pB.next if pB else headA
        return pA
        '''