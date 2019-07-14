/*
����һ���������ĸ��ڵ㣬�жϸ����ǲ���ƽ���������
���ĳ������������ڵ��������������������� 1����ô������һ��ƽ��������� 
*/ 

// ���������ķ�ʽ������������ÿ���ڵ㣬�ڱ�����һ���ڵ�֮ǰ���Ѿ���������������������
// ֻҪ�ڱ���ÿ���ڵ��ʱ���¼������ȣ�ĳһ�ڵ����ȵ�������Ҷ�ڵ��·���ĳ��ȣ���
// �Ϳ���һ�߱���һ���ж�ÿ���ڵ��ǲ���ƽ��ģ�ÿ���ڵ�ֻ����һ�Ρ�
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
// ��������ÿ���ڵ��ʱ�򣬵��ú��� TreeDepth �õ�����������������ȣ����ظ������ڵ���
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
