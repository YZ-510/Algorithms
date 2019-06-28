/*
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ�������� head��
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
// �ڲ��ø����ռ�������ʵ�� O(n) ��ʱ�临�Ӷ� 
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        
        return ReconnectNodes(pHead);
    }
    
    // ����ԭʼ�����ÿ���ڵ� N �������½ڵ� N'���ٰ� N' ���ӵ� N �ĺ��档 
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while(pNode != nullptr)
        {
            RandomListNode* pCloned = new RandomListNode(pNode->label);
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = nullptr;
            
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }
    
    // ���ø��ƽڵ�� random�����ԭʼ�����ϵĽڵ� N �� random ָ�� S��
	// ������Ӧ�ĸ��ƽڵ� N' �� random ָ�� S �ĸ��ƽڵ� S'�� 
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while(pNode != nullptr)
        {
            RandomListNode* pCloned = pNode->next;
            if(pNode->random != nullptr)
                pCloned->random = pNode->random->next;
            
            pNode = pCloned->next;
        }
    }
    
    // ������������ֳ���������������λ�õĽڵ��� next ������������ԭʼ����
	// ��ż��λ�õĽڵ��� next �����������Ǹ��Ƴ��������� 
    RandomListNode* ReconnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = nullptr;
        RandomListNode* pClonedNode = nullptr;
        
        if(pNode != nullptr)
        {
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        
        while(pNode != nullptr)
        {
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        
        return pClonedHead;
    }
};
