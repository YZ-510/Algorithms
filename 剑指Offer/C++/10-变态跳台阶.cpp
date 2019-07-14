/*
һֻ����һ�ο������� 1 ��̨�ף�Ҳ�������� 2 ��������Ҳ�������� n ����
�����������һ�� n ����̨���ܹ��ж�����������
*/

// f(n) = f(n-1) * 2��n > 1; f(1) = 1
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0)
            return -1;
        
        vector<int> res;
        res.push_back(1);
        
        for(int i = 1; i < number; ++i)
            res.push_back(res.back() * 2);	// back() �õ� vector ���һ�����ݵ�����
        
        return res.back();
    }
};
