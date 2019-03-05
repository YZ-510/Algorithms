# 复制带随机指针的链表
# https://leetcode-cn.com/problems/copy-list-with-random-pointer/

# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        # 使用字典记录原链表和新链表每个节点的对应关系
        nodeDict = dict()
        dummy = RandomListNode(0)
        pointer, newHead = head, dummy
        # 得到只有 next 的新链表
        while pointer:
            newNode = RandomListNode(pointer.label)
            nodeDict[pointer] = newNode
            newHead.next = newNode
            pointer, newHead = pointer.next, newHead.next
        pointer, newHead = head, dummy.next
        # 再次循环，得到带 random 的链表
        while pointer:
            if pointer.random:
                newHead.random = nodeDict[pointer.random]
            pointer, newHead = pointer.next, newHead.next
            
        return dummy.next
        
        '''
        if not head:
            return head
        tmp = head
        # 原链表每个节点后面都插入一个新节点，新节点的内容和前面的节点一样
        while tmp:
            newNode = RandomListNode(tmp.label)
            newNode.next = tmp.next
            tmp.next = newNode
            tmp = tmp.next.next
        tmp = head
        while tmp:
            # 拷贝原链表节点的随机节点，修改 random 指针
            if tmp.random:
                tmp.next.random = tmp.random.next
            tmp = tmp.next.next
        
        # 将新链表拆分出来
        newhead = head.next
        pold = head
        pnew = newhead
        while pnew.next:
            pold.next = pnew.next
            pold = pold.next
            pnew.next = pold.next
            pnew = pnew.next
        pold.next = None
        pnew.next = None
        return newhead
        '''
