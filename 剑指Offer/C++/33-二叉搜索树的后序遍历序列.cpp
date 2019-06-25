/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
���������� Yes,������� No���������������������������ֶ�������ͬ��
*/

// ������������У����һ�����������ĸ��ڵ��ֵ��
// ������ǰ������ֿ��Է�Ϊ�����֣���һ�������������ڵ��ֵ�����Ƕ��ȸ��ڵ��ֵС��
// �ڶ��������������ڵ��ֵ�����Ƕ��ȸ��ڵ��ֵ�󡣵ݹ��ж� 
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
        // �ڶ������������������ڵ��ֵС�ڸ��ڵ��ֵ
        int i = begin;
        for(; i < end; ++i)
        {
            if(sequence[i] > root)
                break;
        }
        // �ڶ������������������ڵ��ֵ���ڸ��ڵ��ֵ
        int j = i;
        for(; j < end; ++j)
        {
            if(sequence[j] < root)
                return false;
        }
        // �ж��������ǲ��Ƕ���������
        bool left = true;
        if(i > begin)
            left = bst(sequence, begin, i - 1);
        // �ж��������ǲ��Ƕ���������
        bool right = true;
        if(i < end - 1)
            right = bst(sequence, i, end - 1);
        
        return (left && right);
    }
};
