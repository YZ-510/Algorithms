/*
���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
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
// ��Ҫ����������һ��������ʾ�ڵ�ǰ���л�û�д�ӡ�Ľڵ�������һ��������ʾ��һ��ڵ����Ŀ�� 
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if(pRoot == nullptr)
                return res;
            
            queue<TreeNode*> nodes;
            nodes.push(pRoot);
            // nextLevel ��ʾ��һ��Ľڵ�����toBePrinted ��ʾ�ڵ�ǰ���л�û�д�ӡ�Ľڵ�����
			// ���һ���ڵ����ӽڵ㣬��ÿ��һ���ӽڵ������У�ͬʱ�ѱ��� nextLevel �� 1;
			// ÿ��ӡһ���ڵ㣬toBePrinted �� 1���� toBePrinted ��� 0 ʱ����ʾ��ǰ������нڵ��Ѿ���ӡ��ϡ� 
            int nextLevel = 0;
            int toBePrinted = 1;
            vector<int> line;
            while(!nodes.empty())
            {
                TreeNode* pNode = nodes.front();
                line.push_back(pNode->val);
                if(pNode->left != nullptr)
                {
                    nodes.push(pNode->left);
                    ++nextLevel;
                }
                if(pNode->right != nullptr)
                {
                    nodes.push(pNode->right);
                    ++nextLevel;
                }
                nodes.pop();
                --toBePrinted;
                if(toBePrinted == 0)
                {
                    res.push_back(line);
                    line.clear();
                    toBePrinted = nextLevel;
                    nextLevel = 0;
                }
            }
            
            return res;
        }
    
};
