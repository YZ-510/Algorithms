/*
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
���磬�����ַ��� ��abcdefg�������� 2���ú�������������ת��λ�õ��Ľ�� ��cbefgab���� 
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int length = str.size();
        if(length > 0 && n > 0 && n < length)
        {
            int pFirstStart = 0;
            int pFirstEnd = n - 1;
            int pSecondStart = n;
            int pSecondEnd = length - 1;
            
            // ��ת�ַ�����ǰ�� n ���ַ�
            Reverse(str, pFirstStart, pFirstEnd);
            // ��ת�ַ����ĺ��沿��
            Reverse(str, pSecondStart, pSecondEnd);
            // ��ת�����ַ���
            Reverse(str, pFirstStart, pSecondEnd);
        }
        
        return str;
    }
    
    void Reverse(string &str, int begin, int end)
    {
        while(begin < end)
        {
            char temp = str[begin];
            str[begin] = str[end];
            str[end] = temp;
            begin++;
            end--;
        }
    }
};
