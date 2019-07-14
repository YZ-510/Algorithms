/*
输入一棵二叉树，求该树的深度。
从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
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

// 一棵树只有一个节点，那么它的深度为 1。
// 如果根节点只有左子树而没有右子树，那么树的深度应该是其左子树的深度加 1；
// 如果根节点只有右子树而没有左子树，那么该树的深度就是其右子树的深度加 1；
// 如果既有左子树又有右子树，那么该树的深度就是其左、右子树深度的较大值再加 1。
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
