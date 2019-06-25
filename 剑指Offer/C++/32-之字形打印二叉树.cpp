/*
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
// ��Ҫ����ջ����ӡĳһ��Ľڵ�ʱ������һ����ӽڵ㱣�浽��Ӧ��ջ�
// �����ǰ��ӡ���������㣨��һ�㡢������ȣ������ȱ������ӽڵ��ٱ������ӽڵ㵽��һ��ջ�
// �����ǰ��ӡ����ż���㣨�ڶ��㡢���Ĳ�ȣ������ȱ������ӽڵ��ٱ������ӽڵ㵽�ڶ���ջ� 
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == nullptr)
            return res;
        
        // ����������ջ levels[0] �� levels[1] 
        // �ڴ�ӡһ��ջ��Ľڵ�ʱ�������ӽڵ㱣�浽��һ��ջ�
		// ��һ�����нڵ㶼��ӡ���ʱ������������ջ��������ӡ��һ�㡣 
        stack<TreeNode*> levels[2];
        int current = 0;
        int next = 1;
        
        levels[current].push(pRoot);
        vector<int> line;
        while(!levels[0].empty() || !levels[1].empty())
        {
            TreeNode* pNode = levels[current].top();
            levels[current].pop();
            line.push_back(pNode->val);
            
            if(current == 0)
            {
                if(pNode->left != nullptr)
                    levels[next].push(pNode->left);
                if(pNode->right != nullptr)
                    levels[next].push(pNode->right);
            }
            else
            {
                if(pNode->right != nullptr)
                    levels[next].push(pNode->right);
                if(pNode->left != nullptr)
                    levels[next].push(pNode->left);
            }
            
            if(levels[current].empty())
            {
                res.push_back(line);
                line.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        
        return res;
    }
    
};
