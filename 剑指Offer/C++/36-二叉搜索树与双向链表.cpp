/*
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/

// �ڶ����������У����ӽڵ��ֵ����С�ڸ��ڵ��ֵ�����ӽڵ��ֵ���Ǵ��ڸ��ڵ��ֵ��
// ԭ��ָ�����ӽڵ��ָ�����Ϊ������ָ��ǰһ���ڵ��ָ�룬ԭ��ָ�����ӽڵ��ָ�����Ϊ������ָ���һ���ڵ��ָ�롣
 
// ����������ڰ�����������ת��������˫������֮���ٺ͸��ڵ�����������
// �������������Ľڵ㡢���ڵ㡢����������С�Ľڵ��������� 
// ���ڵ��������ת����һ�������������ʱ�����е����һ���ڵ��ǵ�ǰֵ���Ľڵ㣬
// �͸��ڵ��������������Ѹ��ڵ������������С�Ľڵ�����������
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *pLastNodeInList = nullptr;
        ConvertNode(pRootOfTree, &pLastNodeInList);
        
        // pLastNodeInList ָ��˫�������β�ڵ㣬������Ҫ����ͷ�ڵ�
        TreeNode *pHeadOfList = pLastNodeInList;
        while(pHeadOfList != nullptr && pHeadOfList->left != nullptr)
            pHeadOfList = pHeadOfList->left;
        
        return pHeadOfList;
    }
    
    void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList)
    {
        if(pNode == nullptr)
            return;
        
        TreeNode *pCurrent = pNode;
        
        if(pCurrent->left != nullptr)
            ConvertNode(pCurrent->left, pLastNodeInList);
        
        pCurrent->left = *pLastNodeInList;
        if(*pLastNodeInList != nullptr)
            (*pLastNodeInList)->right = pCurrent;
        
        *pLastNodeInList = pCurrent;
        
        if(pCurrent->right != nullptr)
            ConvertNode(pCurrent->right, pLastNodeInList);
    }
};
