/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

//首先把 n 和 1 做与运算，判断 n 的最低位是不是为 1。接着把 1 左移一位得到 2，
//再和 n 做与运算，就能判断 n 的低次位是不是 1。这样反复左移，每次都能判断 n 的其中一位是不是 1、 
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         unsigned int flag = 1;
         while(flag)
         {
             if(n & flag)
                 count++;
             
             flag = flag << 1;
         }
         
         return count;
     }
};


//把一个整数减去 1，再和原整数做与运算，会把该整数的二进制表示中最右边的 1 变成 0。
//一个整数的二进制表示中有多少个 1，就可以进行多少次这样的操作。
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         
         while(n)
         {
             ++count;
             n = (n - 1) & n;
         }
         
         return count;
     }
};
