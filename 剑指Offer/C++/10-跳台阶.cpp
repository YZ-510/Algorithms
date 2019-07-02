/*
一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
*/

// 把 n 阶台阶时的跳法看成 n 的函数，记为 f(n)。
// 当 n > 2 时，第一次跳的时候就有两种不同的选择：一是第一次只跳 1 级，此时跳法数目等于后面剩下的 n-1 级台阶的跳法数目，即为 f(n-1)； 
// 二是第一次跳 2 级，此时跳法数目等于后面剩下的 n-2 级台阶的跳法数目，即为 f(n-2)。
// 因此，n 级台阶的不同跳法的总数 f(n) = f(n-1) + f(n-2)。 
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2)
            return number;
        
        int fibNMinusOne = 1;
        int fibNMinusTwo = 2;
        int fiN = 0;
        for(int i = 3; i <= number; ++i)
        {
            fiN = fibNMinusOne + fibNMinusTwo;
            fibNMinusOne = fibNMinusTwo;
            fibNMinusTwo = fiN;
        }
        
        return fiN;
    }
};
