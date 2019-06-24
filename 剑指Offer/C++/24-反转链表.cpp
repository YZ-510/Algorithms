/*
输入一个链表，反转链表后，输出新链表的表头。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pReversedHead = nullptr;
        ListNode* pNode = pHead;
        ListNode* pPrev = nullptr;
        while(pNode != nullptr)
        {
            ListNode* pNext = pNode->next;
            
            if(pNext == nullptr)
                pReversedHead = pNode;
            
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        
        return pReversedHead;
    }
};
