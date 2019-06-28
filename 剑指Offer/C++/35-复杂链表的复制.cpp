/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的 head。
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
// 在不用辅助空间的情况下实现 O(n) 的时间复杂度 
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        
        return ReconnectNodes(pHead);
    }
    
    // 复制原始链表的每个节点 N 并创建新节点 N'，再把 N' 链接到 N 的后面。 
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
    
    // 设置复制节点的 random，如果原始链表上的节点 N 的 random 指向 S，
	// 则它对应的复制节点 N' 的 random 指向 S 的复制节点 S'。 
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
    
    // 把这个长链表拆分成两个链表：把奇数位置的节点用 next 链接起来就是原始链表，
	// 把偶数位置的节点用 next 链接起来就是复制出来的链表。 
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
