/*
输入一个二叉树的根节点，判断该树是不是平衡二叉树。
如果某二叉树中任意节点的左右子树的深度相差不超过 1，那么它就是一棵平衡二叉树。 
*/ 

// 后续遍历的方式遍历二叉树的每个节点，在遍历到一个节点之前就已经遍历了它的左、右子树。
// 只要在遍历每个节点的时候记录它的深度（某一节点的深度等于它到叶节点的路径的长度），
// 就可以一边遍历一边判断每个节点是不是平衡的，每个节点只遍历一次。
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot, &depth);
    }
    
    bool IsBalanced(TreeNode* pRoot, int* pDepth)
    {
        if(pRoot == nullptr)
        {
            *pDepth = 0;
            return true;
        }
        
        int left, right;
        if(IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right))
        {
            int diff = left - right;
            if(diff <= 1 && diff >= -1)
            {
                *pDepth = 1 + (left > right ? left : right);
                return true;
            }
        }
        
        return false;
    }
};

/* 
// 遍历树的每个节点的时候，调用函数 TreeDepth 得到它的左、右子树的深度，需重复遍历节点多次
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        int diff = left - right;
        if(diff > 1 || diff < -1)
            return false;
        
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == nullptr)
            return 0;
        
        int nLeft = TreeDepth(pRoot->left);
        int nRight = TreeDepth(pRoot->right);
        
        return (nLeft > nRight) ? nLeft + 1 : nRight + 1;
    }
};
*/ 
