/*
����һ������������ֵ��β��ͷ��˳�򷵻�һ�� ArrayList��
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        stack<int> arr;
        
        ListNode* pNode = head;
        while(pNode != nullptr)
        {
            arr.push(pNode->val);
            pNode = pNode->next;
        }
        
        while(!arr.empty())
        {
            res.push_back(arr.top());
            arr.pop();
        }
        
        return res;
    }
};

// �ݹ飬ÿ���ʵ�һ���ڵ��ʱ���ȵݹ����������Ľڵ㣬������ýڵ����� 
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        PrintListReversingly_Recursively(head, res);
        
        return res;
    }
    
    void PrintListReversingly_Recursively(ListNode* head, vector<int> &res)
    {
        if(head != nullptr)
        {
            if(head->next != nullptr)
                PrintListReversingly_Recursively(head->next, res);
            
            res.push_back(head->val);
        }
    }
};
