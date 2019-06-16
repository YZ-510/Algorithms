/*
现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n <= 39
*/

// 把递归的算法用循环实现，自下而上的循环、从小到大计算 

class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if(n < 2)
            return result[n];
        
        int fibNMinusOne = 1;
        int fibNMinusTwo = 0;
        int fibN = 0;
        for(int i = 2; i <= n; ++i)
        {
            fibN = fibNMinusOne + fibNMinusTwo;
            
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        
        return fibN;
    }
};
