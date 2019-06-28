/*
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ��������� {1,2,4,7,3,5,6,8} ������������� {4,7,2,1,5,3,8,6}�����ؽ������������ء�
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
        // ǰ��������еĵ�һ�������Ǹ��ڵ��ֵ
        int rootValue = startPre[0];
        TreeNode* root = new TreeNode(startPre[0]);
        root->val = rootValue;
        root->left = root->right = nullptr;
        
        if(startPre == endPre)
        {
            // ֻ��һ���ڵ�Ķ�����
            if(startVin == endVin && *startPre == *startVin)
                return root;
            //else
            //    throw std::exception("Invalid input.");
        }
        
        // ����������������ҵ����ڵ��ֵ
        int* rootVin = startVin;
        while(rootVin <= endVin && *rootVin != rootValue)
            ++rootVin;
        
        // ��ƥ��
        //if(rootVin == endVin && *rootVIn != rootValue)
        //    throw std::exception("Invalid input.");
        
        int leftLength = rootVin - startVin;
        int* leftPreEnd = startPre + leftLength;
        if(leftLength > 0)
        {
            // ����������
            root->left = ConstructCore(startPre + 1, leftPreEnd, startVin, rootVin - 1);
        }
        if(leftLength < endPre - startPre) // �ж��Ƿ�ֻ�������� 
        {
            // ����������
            root->right = ConstructCore(leftPreEnd + 1, endPre, rootVin + 1, endVin);
        }
        
        return root;
    }
};
