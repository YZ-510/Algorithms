/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出 Yes,否则输出 No。假设输入的数组的任意两个数字都互不相同。
*/

// 后序遍历序列中，最后一个数字是树的根节点的值。
// 数组中前面的数字可以分为两部分：第一部分是左子树节点的值，它们都比根节点的值小；
// 第二部分是右子树节点的值，它们都比根节点的值大。递归判断 
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        
        return bst(sequence, 0, sequence.size() - 1);
    }
    
    bool bst(vector<int> sequence, int begin, int end)
    {
        if(sequence.empty() || begin > end)
            return false;
        
        int root = sequence[end];
        // 在二叉搜索树中左子树节点的值小于根节点的值
        int i = begin;
        for(; i < end; ++i)
        {
            if(sequence[i] > root)
                break;
        }
        // 在二叉搜索树中右子树节点的值大于根节点的值
        int j = i;
        for(; j < end; ++j)
        {
            if(sequence[j] < root)
                return false;
        }
        // 判断左子树是不是二叉搜索树
        bool left = true;
        if(i > begin)
            left = bst(sequence, begin, i - 1);
        // 判断右子树是不是二叉搜索树
        bool right = true;
        if(i < end - 1)
            right = bst(sequence, i, end - 1);
        
        return (left && right);
    }
};
