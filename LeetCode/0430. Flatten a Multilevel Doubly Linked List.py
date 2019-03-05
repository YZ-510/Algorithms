# 扁平化多级双向链表
# https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return head
        
        p = head
        while p:
            if not p.child:
                p = p.next
                continue
            
            p1 = p.child
            p2 = p.child
            while p2.next:
                p2 = p2.next
            
            p2.next = p.next
            if p.next:
                p.next.prev = p2
            p.next = p1
            p1.prev = p
            p.child = None
            p = p1
        
        return head
        
        
        '''
        if not head:
            return head
        
        res = Node(None, None, head, None)
        while head:
            if head.child:
                child = head.child
                child.prev = head
                while child.next:
                    child = child.next
                child.next = head.next
                if head.next:
                    head.next.prev = child
                head.next = head.child
                head.child = None
            head = head.next
            
        return res.next
        '''
