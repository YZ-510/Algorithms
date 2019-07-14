/*
0，1,…,n-1 这 n 个数字排成一个圆圈，从数字 0 开始，每次从这个圆圈里删除第 m 个数字。
求出这个圆圈里剩下的最后一个数字，约瑟夫环问题。
*/ 

/*
定义一个关于 n 和 m 的方程 f(n,m)，表示每次在 n 个数字中删除第 m 个数字最后剩下的数字。
第一个被删除的数字是（m-1）% n，下一次删除从数字（m-1）% n + 1 开始计数。 
分析被删除数字的规律，递推公式：f(n,m) = [f(n-1,m) + m] % n，n > 1；n = 1 时，f(n,m) = 0。
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
// 创建一个共有 n 个节点的环形链表，然后每次在这个链表中删除第 m 个节点。
// 用模板库中的 std::list 来模拟一个环形链表，当迭代器（Iterator）扫描到链表末尾时，
// 要把迭代器移到链表的头部，这样就相当于按照顺序在一个圆圈里遍历了。
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
