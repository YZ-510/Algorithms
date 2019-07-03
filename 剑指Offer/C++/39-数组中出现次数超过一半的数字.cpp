/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ 9 ������ {1,2,3,2,2,2,5,4,2}����������2�������г����� 5 �Σ�
�������鳤�ȵ�һ�룬������ 2���������������� 0��
*/ 

// ��������ʱ��������ֵ��һ���������е����֣���һ���Ǵ�����
// ����������һ�����ֵ�ʱ�������һ�����ֺ�����֮ǰ�����������ͬ��������� 1��
// �����һ�����ֺ�����֮ǰ��������ֲ�ͬ��������� 1���������Ϊ 0����ô��Ҫ������һ�����֣����Ѵ�����Ϊ 1.
// ����Ҫ�ҵ����ֳ��ֵĴ����������������ֳ��ֵĴ���֮�ͻ�Ҫ�࣬Ҫ�ҵ����ֿ϶������һ�ΰѴ�����Ϊ 1 ʱ��Ӧ�����֡� 
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); ++i)
        {
            if(times == 0)
            {
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
                times++;
            else
                times--;
        }
        
        // �ж� result ���ִ����Ƿ񳬹����鳤�ȵ�һ�� 
        times = 0;
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(numbers[i] == result)
                times++;
        }
        if(times * 2 <= numbers.size())
            return 0;
        
        return result;
    }
};
