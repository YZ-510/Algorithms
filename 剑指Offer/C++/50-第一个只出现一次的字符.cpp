/*
在一个字符串(0 <= 字符串长度 <= 10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/

// 定义哈希表的键值是字符，而值是该字符出现的次数，从头开始扫描自负床两次。 
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() == 0)
            return -1;
        
        map<char, int> mp;
        for(int i = 0; i < str.size(); ++i)
            mp[str[i]]++;
        
        for(int i = 0; i < str.size(); ++i)
        {
            if(mp[str[i]] == 1)
                return i;
        }
        
        return -1;
    }
};
