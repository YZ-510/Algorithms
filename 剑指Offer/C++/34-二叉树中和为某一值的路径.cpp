/*
输入一颗二叉树的根节点和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从树的根节点开始往下一直到叶结点所经过的节点形成一条路径。
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
// 用前序遍历的方式访问到某一节点时，把该节点添加到路径上，并累加该节点的值。
// 如果该节点为叶节点，并且路径中节点值的和刚好等于输入的整数，保存该路径；
// 如果当前节点不是叶节点，则继续访问它的子节点。
// 当前节点访问结束后，递归函数自动回到它的父节点，且需要在路径上删除当前节点并减去当前节点的值。 
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        if(root == nullptr)
            return res;
        
		// 用 vector 实现了一个栈来保存路径
		// 每次用 push_back 在路径的末尾添加节点，用 pop_back 在路径的末尾删除节点 
        vector<int> path;
        int currentSum = 0;
        FindPath(res, root, expectNumber, path, currentSum);
        
        return res;
    }
    
    void FindPath(vector<vector<int> > &res, TreeNode* root, int expectNumber, vector<int> path, int currentSum)
    {
        currentSum += root->val;
        path.push_back(root->val);
        
        // 如果是叶节点，且路径上节点值的和等于输入的值
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if(currentSum == expectNumber && isLeaf)
            res.push_back(path);
        
        // 如果不是叶节点，则遍历它的子节点
        if(root->left != nullptr)
            FindPath(res, root->left, expectNumber, path, currentSum);
        if(root->right != nullptr)
            FindPath(res, root->right, expectNumber, path, currentSum);
        
        // 在返回父节点之前，在路径上删除当前节点
        path.pop_back();
    }
};
