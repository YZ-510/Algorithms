/*
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�� ��%20����
���磬���ַ���Ϊ We Are Happy.�򾭹��滻֮����ַ���Ϊ We%20Are%20Happy��
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length <= 0)
            return;
        
        // �ַ��� string ��ʵ�ʳ���
        int originalLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while(str[i] != '\0')
        {
            ++originalLength;
            
            if(str[i] == ' ')
                ++numberOfBlank;
            
            ++i;
        }
        
        // �ѿո��滻�� '%20' ֮��ĳ���
        int newLength = originalLength + numberOfBlank * 2;
        if(newLength > length)
            return;
        
        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
        {
            if(str[indexOfOriginal] == ' ')
            {
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            }
            else
            {
                str[indexOfNew--] = str[indexOfOriginal];
            }
            
            --indexOfOriginal;
        }
	}
};
