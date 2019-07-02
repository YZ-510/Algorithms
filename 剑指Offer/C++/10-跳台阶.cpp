/*
һֻ����һ�ο������� 1 ��̨�ף�Ҳ�������� 2 ���������������һ�� n ����̨���ܹ��ж�����������
*/

// �� n ��̨��ʱ���������� n �ĺ�������Ϊ f(n)��
// �� n > 2 ʱ����һ������ʱ��������ֲ�ͬ��ѡ��һ�ǵ�һ��ֻ�� 1 ������ʱ������Ŀ���ں���ʣ�µ� n-1 ��̨�׵�������Ŀ����Ϊ f(n-1)�� 
// ���ǵ�һ���� 2 ������ʱ������Ŀ���ں���ʣ�µ� n-2 ��̨�׵�������Ŀ����Ϊ f(n-2)��
// ��ˣ�n ��̨�׵Ĳ�ͬ���������� f(n) = f(n-1) + f(n-2)�� 
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2)
            return number;
        
        int fibNMinusOne = 1;
        int fibNMinusTwo = 2;
        int fiN = 0;
        for(int i = 3; i <= number; ++i)
        {
            fiN = fibNMinusOne + fibNMinusTwo;
            fibNMinusOne = fibNMinusTwo;
            fibNMinusTwo = fiN;
        }
        
        return fiN;
    }
};
