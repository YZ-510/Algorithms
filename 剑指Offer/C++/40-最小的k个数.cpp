/*
���� n ���������ҳ�������С�� K ������
�������� 4, 5, 1, 6, 2, 7, 3, 8 �� 8 �����֣�����С�� 4 �������� 1, 2, 3, 4��
*/ 

// �����и��ڵ��ֵ���Ǵ�����������������ڵ��ֵ��ÿ�ο����� O(1) ʱ���ڵõ����е� k �������е����ֵ��
// ����Ҫ O(logk) ʱ�����ɾ������������������ڴӺ������������ҳ���С�� k �����֡�
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int length = input.size();
        vector<int> res;
        if(length <= 0 || k > length || k <= 0)
            return res;
        
        for(int i = 0; i < k; ++i)
            res.push_back(input[i]);
        // ���ѣ�Ĭ���������� 
        make_heap(res.begin(), res.end());
        
        for(int i = k; i < length; ++i)
        {
            if(input[i] < res[0])
            {
            	// �ȵ����Ѷ�Ԫ�أ��ٴ�������ɾ�� 
                pop_heap(res.begin(), res.end());
                res.pop_back();
                // ���������м���Ԫ�أ��ٵ��� push_heap ����в���һ��Ԫ�� 
                res.push_back(input[i]);
                push_heap(res.begin(), res.end());
            }
        }
        // ʹ���С������� 
        sort_heap(res.begin(), res.end());
        
        return res;
    }
};
