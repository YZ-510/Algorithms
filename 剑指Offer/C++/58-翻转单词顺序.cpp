/*
����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣Ϊ������������ź���ĸһ������ 
���������ַ�����I am a student.�����������student. a am I���� 
*/

// ͨ�����η�ת�ַ�������һ����ת���������е��ַ����ڶ����ٷ�תÿ���������ַ���˳��
class Solution {
public:
    string ReverseSentence(string str) {
        int length = str.length();
        if(length == 0)
            return "";
        
        // ��ת�������� 
        Reverse(str, 0, length - 1);
        
        int begin = 0;
        int end = 0;
        // ��ת�����е�ÿ�����ʣ����ʱ��ո���ŷָ���ͨ��ɨ��ո���ȷ��ÿ�����ʵ���ʼ����ֹλ��
        // begin ָ�򵥴ʵĵ�һ���ַ���end ָ�򵥴ʵ����һ���ַ�
        while(str[begin] != '\0')
        {
            if(str[begin] == ' ')	// ������ʼ�ַ� begin ָ��ո�begin �� end �Լ�
            {
                begin++;
                end++;
            }
            else if((str[end] == ' ' || str[end] == '\0'))	// ������ֹ�ַ� end ָ��ո񣬷�ת����
            {
                Reverse(str, begin, --end);
                begin = ++end;
            }
            else	// δָ��ո��δ����������end �Լ�
                end++;
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
