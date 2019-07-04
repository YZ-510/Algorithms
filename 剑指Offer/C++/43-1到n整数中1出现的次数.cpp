/*
����һ������ n���� 1~n �� n ��������ʮ���Ʊ�ʾ�� 1 ���ֵĴ�����
���磬���� 12��1~12 ��Щ�����а��� 1 �������� 1��10��11 �� 12��1 һ�������� 5 �Ρ�
*/ 

// �ۼ� 1~n ��ÿ������ 1 ���ֵĴ���������ÿ��ͨ���� 10 �������ж������ĸ�λ�����ǲ��� 1��
// ���������ִ��� 10������� 10 ֮�����жϸ�λ�����ǲ��� 1����ÿ�����ֶ�Ҫ���������������㣬
// ������������� 1 ���ֵĴ���������������� n��n �� O(log(n) λ����Ҫ�ж�ÿһλ�ǲ��� 1��ʱ�临�Ӷ��� O(nlog(n)��
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int number = 0;
        for(unsigned int i = 0; i <= n; ++i)
            number += NumberOf1(i);
        
        return number;
    }
    
    int NumberOf1(unsigned int n)
    {
        int number = 0;
        while(n)
        {
            if(n % 10 == 1)
                number++;
            
            n = n / 10;
        }
        
        return number;
    }
};
