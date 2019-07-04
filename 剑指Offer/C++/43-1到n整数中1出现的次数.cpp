/*
输入一个整数 n，求 1~n 这 n 个整数的十进制表示中 1 出现的次数。
例如，输入 12，1~12 这些整数中包含 1 的数字有 1、10、11 和 12，1 一共出现了 5 次。
*/ 

// 累加 1~n 中每个整数 1 出现的次数，可以每次通过对 10 求余数判断整数的个位数字是不是 1。
// 如果这个数字大于 10，则除以 10 之后再判断个位数字是不是 1。对每个数字都要做除法和求余运算，
// 以求出该数字中 1 出现的次数。如果输入数字 n，n 有 O(log(n) 位，需要判断每一位是不是 1，时间复杂度是 O(nlog(n)。
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int number = 0;
        for(unsigned int i = 0; i <= n; ++i)
            number += NumberOf1(i);
        
        return number;
    }
    
    int NumberOf1(unsigned int n)
    {
        int number = 0;
        while(n)
        {
            if(n % 10 == 1)
                number++;
            
            n = n / 10;
        }
        
        return number;
    }
};
