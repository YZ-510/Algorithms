/*
��һ���ַ���ת����һ������(ʵ�� Integer.valueOf(string)�Ĺ��ܣ����� string ����������Ҫ��ʱ���� 0)��
Ҫ����ʹ���ַ���ת�������Ŀ⺯������ֵΪ 0 �����ַ�������һ���Ϸ�����ֵ�򷵻� 0��
*/

// ���ַ�����ֻ��һ�����Ż��߸��š��ж������Ƿ�����������������������������ֵ 0x7FFF FFFF����С�ĸ������� 0x8000 0000��
class Solution {
public:
	// ����ȫ�ֱ��� g_nStatus ����ǲ��������˷Ƿ�����
    enum Status {kValid = 0, kInvalid};
    int g_nStatus = kValid;
    
    int StrToInt(string str) {
        g_nStatus = kInvalid;
        long long num = 0;
        const char* cstr = str.c_str();
        
        if(cstr != nullptr && *cstr !='\0')
        {
        	// �����ű�ǣ�������ֻ�п��ܳ������ַ����ĵ�һ���ַ����ȴ����һ���ַ�
            bool minus = false;
            if(*cstr == '+')
                cstr++;
            else if(*cstr == '-')
            {
                cstr++;
                minus = true;
            }
            
            if(*cstr != '\0')
                num = StrToIntCore(cstr, minus);
        }
        
        return (int)num;
    }
    
    long long StrToIntCore(const char* digit, bool minus)
    {
        long long num = 0;
        
        while(*digit != '\0')
        {
            if(*digit >= '0' && *digit <= '9')
            {
                int flag = minus ? -1 : 1;
                num = num * 10 + flag * (*digit - '0');
                
                if((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
                {
                	// ��� 
                    num = 0;
                    break;
                }
                digit++;
            }
            else
            {
            	// ���� '0'-'9' ֮����ַ����Ƿ����� 
                num = 0;
                break;
            }
        }
        
        if(*digit == '\0')
            g_nStatus = kValid;
        
        return num;
    }
};
