/*
�������������ҳ����ǵĵ�һ�������ڵ㡣 
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
������������й����ڵ㣬��ô�����ڵ���������������β����������Ǵ����������β����ʼ��ǰ�Ƚϣ���ô���һ����ͬ�Ľڵ��������Ҫ�ҵĽڵ㡣
���Էֱ����������Ľڵ��������ջ����������Ϊ�ڵ��λ������ջ��ջ�����Ƚ�����ջ���Ľڵ��Ƿ���ͬ��ֱ���ҵ����һ����ͬ�Ľڵ㡣
����һ�и��򵥵ķ��������ȱ�����������õ����ǵĳ��ȣ�����֪���ĸ�����Ƚϳ����Լ���������ȶ̵�����༸���ڵ㡣
�ڵڶ��α�����ʱ���ڽϳ����������������ɲ�������ͬʱ�����������ϱ������ҵ���һ����ͬ�Ľڵ�������ǵĵ�һ�������ڵ㡣 
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
        
        // ���ڳ��������߼�������ͬʱ�����������ϱ���
        for(int i = 0; i < nLengthDif; ++i)
            pListHeadLong = pListHeadLong->next;
        
        while((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadLong != pListHeadShort))
        {
            pListHeadLong = pListHeadLong->next;
            pListHeadShort = pListHeadShort->next;
        }
        
        // �õ���һ�������ڵ�
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
