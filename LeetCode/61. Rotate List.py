# 旋转链表
# https://leetcode-cn.com/problems/rotate-list/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return head
        cur = head
        length = 1
        while cur.next:
            length += 1
            cur = cur.next
        tail = cur
        k = k % length
        
        # 找到末端第 k 个节点
        # 快慢指针
        dummy = ListNode(-1)
        dummy.next = head
        fast = dummy
        slow = dummy
        for i in range(k):
            fast = fast.next
        while fast.next:
            slow = slow.next
            fast = fast.next
        
        tail.next = head
        head = slow.next
        slow.next = None
        
        return head