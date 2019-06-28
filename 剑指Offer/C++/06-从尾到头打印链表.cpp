/*
输入一个链表，按链表值从尾到头的顺序返回一个 ArrayList。
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

// 递归，每访问到一个节点的时候，先递归输出它后面的节点，再输出该节点自身。 
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
