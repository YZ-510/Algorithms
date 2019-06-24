/* 
输入两棵二叉树 A，B，判断 B 是不是 A 的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
// 分两步，第一步：遍历树 A，在树 A 中找到和树 B 根节点的值一样的节点 R；
// 第二步：判断树 A 中以 R 为根节点的子树是不是包含和树 B 一样的结构。 
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
    
    // 如果节点 R 的值和树 B 根节点的值相同，递归地判断它们各自的左右节点的值是不是相同， 
    // 递归的终止条件是到达了树 A 或者树 B 的叶节点。 
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
