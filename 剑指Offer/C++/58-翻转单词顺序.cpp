/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和字母一样处理。 
例如输入字符串“I am a student.”，则输出“student. a am I”。 
*/

// 通过两次翻转字符串，第一步翻转句子中所有的字符，第二步再翻转每个单词中字符的顺序。
class Solution {
public:
    string ReverseSentence(string str) {
        int length = str.length();
        if(length == 0)
            return "";
        
        // 翻转整个句子 
        Reverse(str, 0, length - 1);
        
        int begin = 0;
        int end = 0;
        // 翻转句子中的每个单词，单词被空格符号分隔，通过扫描空格来确当每个单词的起始和终止位置
        // begin 指向单词的第一个字符，end 指向单词的最后一个字符
        while(str[begin] != '\0')
        {
            if(str[begin] == ' ')	// 单词起始字符 begin 指向空格，begin 和 end 自加
            {
                begin++;
                end++;
            }
            else if((str[end] == ' ' || str[end] == '\0'))	// 单词终止字符 end 指向空格，翻转单词
            {
                Reverse(str, begin, --end);
                begin = ++end;
            }
            else	// 未指向空格或未遍历结束，end 自加
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
