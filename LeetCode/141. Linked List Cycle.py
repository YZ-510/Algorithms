# 环形链表
# https://leetcode-cn.com/problems/linked-list-cycle/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 用字典记录每个节点是否被访问过
        
        lookup = {}
        while head:
            if head in lookup:
                return True
            lookup[head] = 1
            head = head.next
            
        return False
        
        '''
        快慢指针，fast 每次移动两个节点，slow 每次移动一个节点
        若 fast == slow，说明存在环
        
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                return True
        
        return False
        '''