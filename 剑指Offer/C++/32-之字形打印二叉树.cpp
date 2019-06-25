/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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
// 需要两个栈：打印某一层的节点时，把下一层的子节点保存到相应的栈里。
// 如果当前打印的是奇数层（第一层、第三层等），则先保存左子节点再保存右子节点到第一个栈里；
// 如果当前打印的是偶数层（第二层、第四层等），则先保存右子节点再保存左子节点到第二个栈里。 
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == nullptr)
            return res;
        
        // 定义了两个栈 levels[0] 和 levels[1] 
        // 在打印一个栈里的节点时，它的子节点保存到另一个栈里。
		// 当一层所有节点都打印完毕时，交换这两个栈并继续打印下一层。 
        stack<TreeNode*> levels[2];
        int current = 0;
        int next = 1;
        
        levels[current].push(pRoot);
        vector<int> line;
        while(!levels[0].empty() || !levels[1].empty())
        {
            TreeNode* pNode = levels[current].top();
            levels[current].pop();
            line.push_back(pNode->val);
            
            if(current == 0)
            {
                if(pNode->left != nullptr)
                    levels[next].push(pNode->left);
                if(pNode->right != nullptr)
                    levels[next].push(pNode->right);
            }
            else
            {
                if(pNode->right != nullptr)
                    levels[next].push(pNode->right);
                if(pNode->left != nullptr)
                    levels[next].push(pNode->left);
            }
            
            if(levels[current].empty())
            {
                res.push_back(line);
                line.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        
        return res;
    }
    
};
