/* 
�������ö����� A��B���ж� B �ǲ��� A ���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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
// ����������һ���������� A������ A ���ҵ����� B ���ڵ��ֵһ���Ľڵ� R��
// �ڶ������ж��� A ���� R Ϊ���ڵ�������ǲ��ǰ������� B һ���Ľṹ�� 
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1 != nullptr && pRoot2 != nullptr)
        {
            if(Equal(pRoot1->val, pRoot2->val))
                result = DoesTree1HaveTree2(pRoot1, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        
        return result;
    }
    
    // ����ڵ� R ��ֵ���� B ���ڵ��ֵ��ͬ���ݹ���ж����Ǹ��Ե����ҽڵ��ֵ�ǲ�����ͬ�� 
    // �ݹ����ֹ�����ǵ������� A ������ B ��Ҷ�ڵ㡣 
    bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == nullptr)
            return true;
        if(pRoot1 == nullptr)
            return false;
        if(!Equal(pRoot1->val, pRoot2->val))
            return false;
        
        return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) &&
                DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
    }
    
    bool Equal(double num1, double num2)
    {
        if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
            return true;
        else
            return false;
    }
};
