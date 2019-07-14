/*
给定一棵二叉搜索树，请找出其中的第 k 大的结点。
例如（ 5，3，7，2，4，6，8）中，按节点数值大小顺序，第三大节点的值为 4。
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

// 中序遍历一棵二叉搜索树，就能得到一个递增的序列
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k == 0)
            return nullptr;
        
        return KthNodeCore(pRoot, k);
    }

    TreeNode* KthNodeCore(TreeNode* pRoot, int& k)
    {
        TreeNode* target = nullptr;
        
        if(pRoot->left != nullptr)
            target = KthNodeCore(pRoot->left, k);
        
        if(target == nullptr)
        {
            if(k == 1)
                target = pRoot;
            
            k--;
        }
        
        if(target == nullptr && pRoot->right != nullptr)
            target = KthNodeCore(pRoot->right, k);
        
        return target;
    }
};
