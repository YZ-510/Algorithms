/*
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
�����ĸ��ڵ㿪ʼ����һֱ��Ҷ����������Ľڵ��γ�һ��·����
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
// ��ǰ������ķ�ʽ���ʵ�ĳһ�ڵ�ʱ���Ѹýڵ���ӵ�·���ϣ����ۼӸýڵ��ֵ��
// ����ýڵ�ΪҶ�ڵ㣬����·���нڵ�ֵ�ĺ͸պõ�������������������·����
// �����ǰ�ڵ㲻��Ҷ�ڵ㣬��������������ӽڵ㡣
// ��ǰ�ڵ���ʽ����󣬵ݹ麯���Զ��ص����ĸ��ڵ㣬����Ҫ��·����ɾ����ǰ�ڵ㲢��ȥ��ǰ�ڵ��ֵ�� 
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        if(root == nullptr)
            return res;
        
		// �� vector ʵ����һ��ջ������·��
		// ÿ���� push_back ��·����ĩβ��ӽڵ㣬�� pop_back ��·����ĩβɾ���ڵ� 
        vector<int> path;
        int currentSum = 0;
        FindPath(res, root, expectNumber, path, currentSum);
        
        return res;
    }
    
    void FindPath(vector<vector<int> > &res, TreeNode* root, int expectNumber, vector<int> path, int currentSum)
    {
        currentSum += root->val;
        path.push_back(root->val);
        
        // �����Ҷ�ڵ㣬��·���Ͻڵ�ֵ�ĺ͵��������ֵ
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if(currentSum == expectNumber && isLeaf)
            res.push_back(path);
        
        // �������Ҷ�ڵ㣬����������ӽڵ�
        if(root->left != nullptr)
            FindPath(res, root->left, expectNumber, path, currentSum);
        if(root->right != nullptr)
            FindPath(res, root->right, expectNumber, path, currentSum);
        
        // �ڷ��ظ��ڵ�֮ǰ����·����ɾ����ǰ�ڵ�
        path.pop_back();
    }
};
