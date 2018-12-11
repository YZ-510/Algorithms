# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 使用快慢指针找到中间节点
        fast = slow = head
        # 找到中间节点
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # print(fast)
        # print(slow.val)
        # 翻转后半部分
        prev = None
        while slow:
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp
        # 比较前后两部分
        while prev:
            if prev.val != head.val:
                return False
            prev = prev.next
            head = head.next
        return True
    
        '''
        把链表中元素存到数组中进行比较
        
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
            
        return vals == vals[::-1]
        '''