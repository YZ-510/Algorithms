/*
��һ���ַ���(0 <= �ַ������� <= 10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,
����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.
*/

// �����ϣ��ļ�ֵ���ַ�����ֵ�Ǹ��ַ����ֵĴ�������ͷ��ʼɨ���Ը������Ρ� 
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
