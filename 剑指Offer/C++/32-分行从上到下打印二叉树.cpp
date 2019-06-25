/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
// 需要两个变量：一个变量表示在当前层中还没有打印的节点数，另一个变量表示下一层节点的数目。 
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if(pRoot == nullptr)
                return res;
            
            queue<TreeNode*> nodes;
            nodes.push(pRoot);
            // nextLevel 表示下一层的节点数，toBePrinted 表示在当前层中还没有打印的节点数。
			// 如果一个节点有子节点，则每把一个子节点加入队列，同时把变量 nextLevel 加 1;
			// 每打印一个节点，toBePrinted 减 1，当 toBePrinted 变成 0 时，表示当前层的所有节点已经打印完毕。 
            int nextLevel = 0;
            int toBePrinted = 1;
            vector<int> line;
            while(!nodes.empty())
            {
                TreeNode* pNode = nodes.front();
                line.push_back(pNode->val);
                if(pNode->left != nullptr)
                {
                    nodes.push(pNode->left);
                    ++nextLevel;
                }
                if(pNode->right != nullptr)
                {
                    nodes.push(pNode->right);
                    ++nextLevel;
                }
                nodes.pop();
                --toBePrinted;
                if(toBePrinted == 0)
                {
                    res.push_back(line);
                    line.clear();
                    toBePrinted = nextLevel;
                    nextLevel = 0;
                }
            }
            
            return res;
        }
    
};
