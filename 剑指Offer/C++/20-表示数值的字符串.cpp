/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串 "+100"、"5e2"、"-123"、"3.1416" 和 "-1E-16" 都表示数值，
但是 "12e"、"1a3.14"、"1.2.3"、"+-5" 和 "12e+4.3" 都不是。
*/ 

/* 
表示数值的字符串遵循模式 A.[[B][e|EC] 或者 .B[e|EC]，其中 A 为数值的整数部分，
B 紧跟着小数点为数值的小数部分，C 紧着 'e' 或者 'E' 为数值的指数部分，在小数里可能没有数值的整数部分。
判断一个字符串是否符合上述模式，首先尽可能多地扫面 0~9 的数位（有可能在起始处有 '+'、'-'），也就是表示整数的 A 部分。
如果遇到小数点 '.'，则开始扫描表示小数的 B 部分。如果遇到 'e'、'E'，则开始扫描表示指数的 C 部分。
A、C 都是整数（可以有正负号，也可以没有），而 B 是一个无符号整数。
*/
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == nullptr)
            return false;
        
        bool numeric = scanInteger(&string);
        
        // 如果出现 '.'，则接下来是数字的小数部分
        if(*string == '.')
        {
            ++string;
            
            // 下面一行代码用 || 的原因：
			// 1. 小数可以没有整数部分，如 .123 等于 0.123；
			// 2. 小数点后面可以没有数字，如 233. 等于 233.0；
			// 3. 小数点前面和后面都可以有数字
            numeric = scanUnsignedInteger(&string) || numeric;
        }
        
        // 如果出现 'e' 或者 'E'，则接下来是数字的指数部分
        if(*string == 'e' || *string == 'E')
        {
            ++string;
            
            // 下面一行代码用 && 的原因：
			// 1. 当 e 或者 E 前面没有数字时，整个字符串不能表示数字，如 .e1、e1;
			// 2. 当 e 或者 E 后面没有整数时，整个字符串不能表示数字，如 12e、12e+5.4
            numeric = numeric && scanInteger(&string);
        }
        
        return numeric && *string == '\0';
    }
    
    // 扫描字符串中 0~9 中的数位（类似于一个无符号整数），可以用来匹配数值模式中的 B 部分
    bool scanUnsignedInteger(char** str)
    {
        const char* before = *str;
        while(**str != '\0' && **str >= '0' && **str <= '9')
            ++(*str);
        
        // 当 str 中存在若干 0~9 的数字时，返回 true
        return *str > before;
    }
    
    // 扫描可能以 '+'、'-' 为起始的 0~9 的数位（类似于一个可能带正负符号的整数），用来匹配数值模式中的 A 和 C 部分
    bool scanInteger(char** str)
    {
        if(**str == '+' || **str == '-')
            ++(*str);
        
        return scanUnsignedInteger(str);
    }
};
