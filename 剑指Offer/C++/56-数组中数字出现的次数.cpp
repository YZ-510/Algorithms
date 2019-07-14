/*
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
Ҫ��ʱ�临�Ӷ��� O(n)���ռ临�Ӷ��� O(1)�� 
*/ 

/*
�����������ʣ��κ�һ������������Լ������� 0��
��ͷ��β������������е�ÿ�����֣���ô���յĽ����������ֻ����һ�ε����ֵ����������Ϊ��Щ�ɶԳ������ε�����ȫ��������е����ˡ�
�������������ֿ϶���һ�������Ľ���϶���Ϊ 0�������������ֵĶ����Ʊ�ʾ��������һλΪ 1��
�ڽ���������ҵ���һ��Ϊ 1 ��λ��λ�ã���Ϊ�� n λ���Ե� n λ�ǲ��� 1 Ϊ��׼��ԭ�����е����ַ�Ϊ���������飬
��ô���������ε����ֿ϶������䵽ͬһ�������飬��Ϊ������ͬ�����ֵ�����һλ������ͬ�ġ�
��ԭ����ֳ����������飬ʹ��ÿ�����������һ��ֻ����һ�ε����֣����������ֶ����������Ρ�
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty())
            return;
        
        int length = data.size();
        int resultExclusiveOR = 0;
        for(int i = 0; i < length; ++i)
            resultExclusiveOR ^= data[i];
        
        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
        
        *num1 = *num2 = 0;
        for(int j = 0; j < length; ++j)
        {
            if(IsBit1(data[j], indexOf1))
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
        }
    }
    
    // ������ num �Ķ����Ʊ�ʾ���ҵ����ұ��� 1 ��λ 
    unsigned int FindFirstBitIs1(int num)
    {
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
        {
            num = num >> 1;
            ++indexBit;
        }
        
        return indexBit;
    }
    
    // �ж��� num �Ķ����Ʊ�ʾ�д��ұ������ indexBit λ�ǲ��� 1 
    bool IsBit1(int num, unsigned int indexBit)
    {
        num = num >> indexBit;
        return (num & 1);
    }
};
