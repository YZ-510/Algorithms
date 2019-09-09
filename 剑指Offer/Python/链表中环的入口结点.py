# 链表中是否包含环：快慢指针，如果快指针与满指针相遇，链表就包含环；如果快指针到达链表的末尾还未相遇，说明不包含环。
# 得到环中节点的数目：快慢指针相遇的节点一定是在环中，从这个节点出发，一边移动一边计数，当再次回到这个节点时，就得到环中节点数 n。
# 找到环的入口：两个指针，先让一个指针在链表上移动 n 步，然后两个指针同时移动，相遇的节点就是入口节点

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        if pHead == None:
            return None
        
        meetNode = self.MeetNode(pHead)
        if meetNode == None:
            return None
        
        nodesInLoop = 1
        flag = meetNode
        while flag.next != meetNode:
            nodesInLoop += 1
            flag = flag.next
        
        fast = pHead
        for i in range(nodesInLoop):
            fast = fast.next
        slow = pHead
        while fast != slow:
            fast = fast.next
            slow = slow.next
        
        return fast
    
    def MeetNode(self, pHead):
        if pHead == None:
            return None
        
        slow = pHead.next
        if slow == None:
            return None
        
        fast = slow.next
        while fast != None and slow != None:
            if fast == slow:
                return fast
            slow = slow.next
            fast = fast.next
            if fast.next != None:
                fast = fast.next
        
        return None