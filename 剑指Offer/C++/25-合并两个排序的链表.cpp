/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 递归 
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr)
            return pHead2;
        else if(pHead2 == nullptr)
            return pHead1;
        
        ListNode* pMergedHead = nullptr;
        if(pHead1->val < pHead2->val)
        {
            pMergedHead = pHead1;
            pMergedHead->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            pMergedHead = pHead2;
            pMergedHead->next = Merge(pHead1, pHead2->next);
        }
        
        return pMergedHead;
    }
};
