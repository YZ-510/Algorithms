/*
给一个链表，若其中包含环，请找出该链表的环的入口节点，否则，输出null。
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	// 慢指针一次走一步，快指针一次走两步。 
        // 找到快慢指针相遇的节点，即链表中存在环。 
        if(pHead == nullptr)
            return nullptr;
        
        ListNode* pSlow = pHead->next;
        if(pSlow == nullptr)
            return nullptr;
        
        ListNode* pFast = pSlow->next;
        ListNode* meetingNode = nullptr;
        while(pFast != nullptr && pSlow != nullptr)
        {
            if(pFast == pSlow)
            {
                meetingNode = pFast;
                break;
            }
            
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != nullptr)
                pFast = pFast->next;
        }
        
        if(meetingNode == nullptr)
            return nullptr;
        
        // 得到环中节点的数目
        int nodesInLoop = 1;
        ListNode* pNode1 = meetingNode;
        while(pNode1->next != meetingNode)
        {
            pNode1 = pNode1->next;
            ++nodesInLoop;
        }
        
        // 先移动 pNode1，次数为环中节点的数目
        pNode1 = pHead;
        for(int i = 0; i < nodesInLoop; ++i)
            pNode1 = pNode1->next;
        
        // 再移动 pNode1 和 pNode2
        ListNode* pNode2 = pHead;
        while(pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        
        return pNode1;
    }
};

/*
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetingNode = MeetingNode(pHead);
        if(meetingNode == nullptr)
            return nullptr;
        
        // 得到环中节点的数目
        int nodesInLoop = 1;
        ListNode* pNode1 = meetingNode;
        while(pNode1->next != meetingNode)
        {
            pNode1 = pNode1->next;
            ++nodesInLoop;
        }
        
        // 先移动 pNode1，次数为环中节点的数目
        pNode1 = pHead;
        for(int i = 0; i < nodesInLoop; ++i)
            pNode1 = pNode1->next;
        
        // 再移动 pNode1 和 pNode2
        ListNode* pNode2 = pHead;
        while(pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        
        return pNode1;
    }
    
    ListNode* MeetingNode(ListNode* pHead)
    {
        // 找到快慢指针相遇的节点
        if(pHead == nullptr)
            return nullptr;
        
        ListNode* pSlow = pHead->next;
        if(pSlow == nullptr)
            return nullptr;
        
        ListNode* pFast = pSlow->next;
        while(pFast != nullptr && pSlow != nullptr)
        {
            if(pFast == pSlow)
            {
                return pFast;
            }
            
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != nullptr)
                pFast = pFast->next;
        }
        
        return nullptr;
    }
};
*/
