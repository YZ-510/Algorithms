/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列 {1,2,4,7,3,5,6,8} 和中序遍历序列 {4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0)
            return nullptr;
        
        int* startPre = &pre[0];
        int* endPre = &pre[pre.size() - 1];
        int* startVin = &vin[0];
        int* endVin = &vin[vin.size() - 1];
        
        return ConstructCore(startPre, endPre, startVin, endVin);
    }
    
    TreeNode* ConstructCore(int* startPre, int* endPre, int* startVin, int* endVin)
    {
        // 前序遍历序列的第一个数字是根节点的值
        int rootValue = startPre[0];
        TreeNode* root = new TreeNode(startPre[0]);
        root->val = rootValue;
        root->left = root->right = nullptr;
        
        if(startPre == endPre)
        {
            // 只有一个节点的二叉树
            if(startVin == endVin && *startPre == *startVin)
                return root;
            //else
            //    throw std::exception("Invalid input.");
        }
        
        // 在中序遍历序列中找到根节点的值
        int* rootVin = startVin;
        while(rootVin <= endVin && *rootVin != rootValue)
            ++rootVin;
        
        // 不匹配
        //if(rootVin == endVin && *rootVIn != rootValue)
        //    throw std::exception("Invalid input.");
        
        int leftLength = rootVin - startVin;
        int* leftPreEnd = startPre + leftLength;
        if(leftLength > 0)
        {
            // 构建左子树
            root->left = ConstructCore(startPre + 1, leftPreEnd, startVin, rootVin - 1);
        }
        if(leftLength < endPre - startPre) // 判断是否只有左子树 
        {
            // 构建右子树
            root->right = ConstructCore(leftPreEnd + 1, endPre, rootVin + 1, endVin);
        }
        
        return root;
    }
};
