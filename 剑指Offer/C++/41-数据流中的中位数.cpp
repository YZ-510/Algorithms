/*
��εõ�һ���������е���λ����
������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ�� 
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ�� Insert()������ȡ��������ʹ�� GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����
*/ 

// ʹ�����Ѻ���С�ѣ�����Ҫ��֤����ƽ�����䵽�������У���������������ݵ���Ŀ֮��ܳ��� 1��
// Ϊ��ʵ��ƽ�����䣬���������ݵ�����Ŀ��ż��ʱ�������ݲ�����С�ѣ�����������ѡ�
// ��Ҫ��֤��С���е��������ֶ����������е����֡�
// min Ϊ��С�ѣ�max Ϊ���ѣ����� STL �еĺ��� push_heap��pop_heap �� vector ʵ�ֶѣ� 
// �ȽϷº��� less �� greater �ֱ�����ʵ�����Ѻ���С�ѡ�
class Solution {
public:
    void Insert(int num)
    {
        int size = min.size() + max.size();
        // ���ݵ�����Ŀ��ż��ʱ���������ݲ�����С�� 
        if((size & 1) == 0)
        {
        	// ���������С�����������������򽫸����ݲ������ѣ��������������������ó���������С�� 
            if(max.size() > 0 && num < max[0])
            {
            	// ���ݲ������� 
                max.push_back(num);
                // �������� 
                push_heap(max.begin(), max.end(), less<int>());
                
                num = max[0];
                
                //ɾ�����ѵĶѶ�Ԫ�� 
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            // ���ݲ�����С�� 
            min.push_back(num);
            // ������С�� 
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else
        {
        	// ��������ݴ�����С������С�������򽫸����ݲ�����С�ѣ�������С������С�������ó������������� 
            if(min.size() > 0 && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                
                num = min[0];
                
                // ɾ����С�ѵĶѶ�Ԫ�� 
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            // ���ݲ������� 
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    { 
        int size = min.size() + max.size();
        if(size <= 0)
            return 0;
        
        double median;
        if((size & 1) == 1)
            median = min[0];
        else
            median = (min[0] + max[0]) / 2.0;
        
        return median;
    }

private:
    vector<int> min;
    vector<int> max;
};
