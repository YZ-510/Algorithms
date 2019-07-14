/*
输入两个链表，找出它们的第一个公共节点。 
*/ 

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

/* 
如果两个链表有公共节点，那么公共节点出现在两个链表的尾部。如果我们从两个链表的尾部开始往前比较，那么最后一个相同的节点就是我们要找的节点。
可以分别把两个链表的节点放入两个栈里，两个链表的为节点就位于两个栈的栈顶，比较两个栈顶的节点是否相同，直到找到最后一个相同的节点。
还有一中更简单的方法：首先遍历两个链表得到它们的长度，就能知道哪个链表比较长，以及长的链表比短的链表多几个节点。
在第二次遍历的时候，在较长的链表上先走若干步，接着同时在两个链表上遍历，找到第一个相同的节点就是它们的第一个公共节点。 
*/ 
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unsigned int nLength1 = GetListLength(pHead1);
        unsigned int nLength2 = GetListLength(pHead2);
        int nLengthDif = nLength1 - nLength2;
        
        ListNode* pListHeadLong = pHead1;
        ListNode* pListHeadShort = pHead2;
        if(nLength2 > nLength1)
        {
            pListHeadLong = pHead2;
            pListHeadShort = pHead1;
            nLengthDif = nLength2 - nLength1;
        }
        
        // 先在长链表上走几步，再同时在两个链表上遍历
        for(int i = 0; i < nLengthDif; ++i)
            pListHeadLong = pListHeadLong->next;
        
        while((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadLong != pListHeadShort))
        {
            pListHeadLong = pListHeadLong->next;
            pListHeadShort = pListHeadShort->next;
        }
        
        // 得到第一个公共节点
        ListNode* pFistCommonNode = pListHeadLong;
        
        return pFistCommonNode;
    }
    
    unsigned int GetListLength(ListNode* pHead)
    {
        unsigned int nLength = 0;
        ListNode* pNode = pHead;
        while(pNode != nullptr)
        {
            ++nLength;
            pNode = pNode->next;
        }
        
        return nLength;
    }
};
