/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

// 在二叉搜索树中，左子节点的值总是小于父节点的值，右子节点的值总是大于父节点的值。
// 原先指向左子节点的指针调整为链表中指向前一个节点的指针，原先指向右子节点的指针调整为链表中指向后一个节点的指针。
 
// 中序遍历，在把左、右子树都转换成排序双向链表之后再和根节点链接起来。
// 把左子树中最大的节点、根节点、右子树中最小的节点链接起来 
// 根节点的左子树转换成一个排序的链表，此时链表中的最后一个节点是当前值最大的节点，
// 和根节点链接起来，并把根节点和右子树中最小的节点链接起来。
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
        
        // pLastNodeInList 指向双向链表的尾节点，我们需要返回头节点
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
