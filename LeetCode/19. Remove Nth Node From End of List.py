# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        '''
        双指针，fast 先走 n 步，再让 fast 和 slow 一起走
        当 fast.next 为 None，说明走到了末尾
        此时 slow 就是要删除节点的前一个节点
        '''
        dummy = ListNode(-1)
        dummy.next = head
        slow = fast = dummy
        for i in range(n):
            fast = fast.next
#        print(fast.val)
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return dummy.next