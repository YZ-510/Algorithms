# 删除链表的倒数第 N 个节点
# https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        prev = None
        while head.next:
            nxt = head.next
            head.next = prev
            prev = head
            head = nxt
#        print(prev.val)
        head.next = prev
        return head
        
        '''
        三个指针，分别指向前一个节点 prev、当前节点 cur、下一个节点 nxt，逐个翻转节点、遍历一轮
        
        prev = None
        cur = head
        while cur:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        return prev
        '''