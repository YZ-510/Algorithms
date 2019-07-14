/*
0��1,��,n-1 �� n �������ų�һ��ԲȦ�������� 0 ��ʼ��ÿ�δ����ԲȦ��ɾ���� m �����֡�
������ԲȦ��ʣ�µ����һ�����֣�Լɪ�����⡣
*/ 

/*
����һ������ n �� m �ķ��� f(n,m)����ʾÿ���� n ��������ɾ���� m ���������ʣ�µ����֡�
��һ����ɾ���������ǣ�m-1��% n����һ��ɾ�������֣�m-1��% n + 1 ��ʼ������ 
������ɾ�����ֵĹ��ɣ����ƹ�ʽ��f(n,m) = [f(n-1,m) + m] % n��n > 1��n = 1 ʱ��f(n,m) = 0��
*/
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        
        int last = 0;
        for(int i = 2; i <= n; ++i)
            last = (last + m) % i;
        
        return last;
    }
};

/*
// ����һ������ n ���ڵ�Ļ�������Ȼ��ÿ�������������ɾ���� m ���ڵ㡣
// ��ģ����е� std::list ��ģ��һ��������������������Iterator��ɨ�赽����ĩβʱ��
// Ҫ�ѵ������Ƶ������ͷ�����������൱�ڰ���˳����һ��ԲȦ������ˡ�
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        
        unsigned int i = 0;
        
        list<int> numbers;
        for(i = 0; i < n; ++i)
            numbers.push_back(i);
        
        list<int>::iterator current = numbers.begin();
        while(numbers.size() > 1)
        {
            for(int i = 1; i < m; ++i)
            {
                current++;
                if(current == numbers.end())
                    current = numbers.begin();
            }
            
            list<int>::iterator next = ++current;
            if(next == numbers.end())
                next = numbers.begin();
            
            --current;
            numbers.erase(current);
            current = next;
        }
        
        return *(current);
    }
};
*/ 
