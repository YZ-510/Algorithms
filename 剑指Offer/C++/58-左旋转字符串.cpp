/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串 “abcdefg”和数字 2，该函数将返回左旋转两位得到的结果 “cbefgab”。 
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
            
            // 翻转字符串的前面 n 个字符
            Reverse(str, pFirstStart, pFirstEnd);
            // 翻转字符串的后面部分
            Reverse(str, pSecondStart, pSecondEnd);
            // 翻转整个字符串
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
