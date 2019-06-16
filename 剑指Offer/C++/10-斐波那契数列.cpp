/*
����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
n <= 39
*/

// �ѵݹ���㷨��ѭ��ʵ�֣����¶��ϵ�ѭ������С������� 

class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if(n < 2)
            return result[n];
        
        int fibNMinusOne = 1;
        int fibNMinusTwo = 0;
        int fibN = 0;
        for(int i = 2; i <= n; ++i)
        {
            fibN = fibNMinusOne + fibNMinusTwo;
            
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        
        return fibN;
    }
};
