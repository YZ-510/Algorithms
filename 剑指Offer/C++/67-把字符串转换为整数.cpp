/*
将一个字符串转换成一个整数(实现 Integer.valueOf(string)的功能，但是 string 不符合数字要求时返回 0)，
要求不能使用字符串转换整数的库函数，数值为 0 或者字符串不是一个合法的数值则返回 0。
*/

// 空字符串、只有一个正号或者负号、判断整数是否发生上溢出或者下溢出（最大的正整数值 0x7FFF FFFF，最小的负整数是 0x8000 0000）
class Solution {
public:
	// 定义全局变量 g_nStatus 标记是不是遇到了非法输入
    enum Status {kValid = 0, kInvalid};
    int g_nStatus = kValid;
    
    int StrToInt(string str) {
        g_nStatus = kInvalid;
        long long num = 0;
        const char* cstr = str.c_str();
        
        if(cstr != nullptr && *cstr !='\0')
        {
        	// 正负号标记，正负号只有可能出现在字符串的第一个字符，先处理第一个字符
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
                	// 溢出 
                    num = 0;
                    break;
                }
                digit++;
            }
            else
            {
            	// 遇到 '0'-'9' 之外的字符，非法输入 
                num = 0;
                break;
            }
        }
        
        if(*digit == '\0')
            g_nStatus = kValid;
        
        return num;
    }
};
