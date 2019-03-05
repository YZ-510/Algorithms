# 两数相加
# https://leetcode-cn.com/problems/add-two-numbers/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 时间复杂度：O(N)，空间复杂度：O(N)
        
        if not l1:
            return l2
        if not l2:
            return l1
        
        val1, val2 = [l1.val], [l2.val]
        while l1.next:
            val1.append(l1.next.val)
            l1 = l1.next
        while l2.next:
            val2.append(l2.next.val)
            l2 = l2.next
        
        # 转换为字符串
        num_1 = ''.join([str(i) for i in val1[::-1]])
        num_2 = ''.join([str(i) for i in val2[::-1]])
        num = str(int(num_1) + int(num_2))[::-1]
        
        result = ListNode(int(num[0]))
        run_res = result
        for i in range(1, len(num)):
            run_res.next = ListNode(int(temp[i]))
            run_res = run_res.next
        
        return result
        
        '''
        # 递归，每次算一位的相加
        # 时间复杂度：O(N)，空间复杂度：O(1)
        
        if not l1:
            return l2
        if not l2:
            return l1
        
        if l1.val + l2.val < 10:
            l3 = ListNode(l1.val + l2.val)
            l3.next = self.addTwoNumbers(l1.next, l2.next)
        else:
            l3 = ListNode(l1.val + l2.val - 10)
            tmp = ListNode(1)
            tmp.next = None
            l3.next = self.addTwoNumbers(l1.next, self.addTwoNumbers(l2.next, tmp))
            
        return l3
        '''
