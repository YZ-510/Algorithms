/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串 abc,则打印出由字符 a,b,c 所能排列出来的所有字符串 abc,acb,bac,bca,cab和cba。
*/ 

// 递归，求整个字符串的排列可以看成两部：第一步求所有可能出现在第一个位置的字符，即把第一个位置的字符和后面所有的字符交换；
// 第二步固定第一个字符，求后面所有字符的排列，把后面的的所有的字符分成两部分：后面字符的第一个字符，以及这个字符之后的所有字符， 
// 然后把第一个字符逐一和它后面的字符交换。 
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty())
            return res;
        
        Permutation(str, res, 0);
        
        // 此时 res 中排列并不是字典序，需要单独再排下序
        sort(res.begin(), res.end());
        
        return res;
    }
    
    void Permutation(string str, vector<string> & res, int begin)
    {
        if(begin == str.size() - 1)	// 递归结束条件，索引已经指向 str 最后一个元素时 
        {
            if(find(res.begin(), res.end(), str) == res.end())
            	// 如果 res 中不存在 str 才添加，避免 aa 和 aa 重复添加的情况 
                res.push_back(str);
        }
        else
        {
        	
            for(int i = begin; i < str.size(); ++i)
            {
                swap(str[i], str[begin]);
                Permutation(str, res, begin + 1);
                swap(str[i], str[begin]);	// 复位，用以恢复之前字符串的顺序，达到第一个位置的字符一次跟其他位置交换的目的 
            }
        }
    }
    
    void swap(char &fir, char &sec)
    {
        char temp = fir;
        fir = sec;
        sec = temp;
    }
};
