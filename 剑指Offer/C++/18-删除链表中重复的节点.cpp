/*
在一个排序的链表中，存在重复的节点，请删除该链表中重复的节点，重复的节点不保留，返回链表头指针。
例如，链表 1->2->3->3->4->4->5 处理后为 1->2->5
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr)
            return pHead;
        
        ListNode* pPreNode = nullptr;
        ListNode* pNode = pHead;
        while(pNode != nullptr)
        {
            ListNode *pNext = pNode->next;
            bool needDelete = false;
            if(pNext != nullptr && pNext->val == pNode->val)
                needDelete = true;
            
            if(!needDelete)
            {
                pPreNode = pNode;
                pNode = pNode->next;
            }
            else
            {
                int value = pNode->val;
                ListNode* pToBeDel = pNode;
                while(pToBeDel != nullptr && pToBeDel->val == value)
                {
                    pNext = pToBeDel->next;
                    
                    delete pToBeDel;
                    pToBeDel = nullptr;
                    
                    pToBeDel = pNext;
                }
                if(pPreNode == nullptr)
                    pHead = pNext;
                else
                    pPreNode->next = pNext;
                pNode = pNext;
            }
        }
        
        return pHead;
    }
};
