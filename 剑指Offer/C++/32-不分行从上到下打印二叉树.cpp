/*
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        // ���� 
        deque<TreeNode*> deque;
        if(!root)
            return res;
        
        deque.push_back(root);
        
        while(deque.size())
        {
            TreeNode *pNode = deque.front();
            res.push_back(pNode->val);
            deque.pop_front();
            
            if(pNode->left)
                deque.push_back(pNode->left);
            if(pNode->right)
                deque.push_back(pNode->right);
        }
        
        return res;
    }
};
