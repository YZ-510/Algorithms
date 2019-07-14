/*
����һ�ö����������������ȡ�
�Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
/* 

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// һ����ֻ��һ���ڵ㣬��ô�������Ϊ 1��
// ������ڵ�ֻ����������û������������ô�������Ӧ����������������ȼ� 1��
// ������ڵ�ֻ����������û������������ô��������Ⱦ���������������ȼ� 1��
// ���������������������������ô��������Ⱦ���������������ȵĽϴ�ֵ�ټ� 1��
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == nullptr)
            return 0;
        
        int nLeft = TreeDepth(pRoot->left);
        int nRight = TreeDepth(pRoot->right);
        
        return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
    }
};
