/*
把只包含质因子 2、3 和 5的数称作丑数（Ugly Number）。例如 6、8 都是丑数，但 14 不是，因为它包含质因子 7。
习惯上我们把 1 当做是第一个丑数。求按从小到大的顺序的第 N 个丑数。
*/

/* 
按顺序把每个丑数放入数组中，求下一个丑数，每个丑数都是前面的丑数乘以 2、3 或者 5 得到的。
把已有最大的丑数记作 M，该丑数肯定是前面某一个丑数乘以 2、3 或者 5 的结果。
所以我们首先考虑把已有的每个丑数乘以 2，小于或者等于 M 肯定已经在数组中了，
不需要再次考虑；还会得到若干大于 M 的结果 ，但我们只需要第一个大于 M 的结果，
因为我们希望丑数是按从小到大的顺序生成的。对于乘以 2 而言，肯定存在某一个丑数 T2，
排在它之前的每个丑数乘以 2 得到的结果都会小于已有最大的丑数，在它之后的丑数乘以 2 得到的结果都会太大。
只需记下这个丑数的位置，同时每次生成新的丑数的时候去更新这个 T2 即可。 
对于乘以 3 和 5 而言，也存在同样的 T3 和 T5。那么下一个丑数应该是 T2 * 2、T3 * 3 和 T5 * 5 这 3 个数的最小者。 
*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        
        int *pUglyNumbers = new int[index];
        pUglyNumbers[0] = 1;
        int nextUglyIndex = 1;
        
        int *pMultiply2 = pUglyNumbers;
        int *pMultiply3 = pUglyNumbers;
        int *pMultiply5 = pUglyNumbers;
        
        while(nextUglyIndex < index)
        {
            int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
            pUglyNumbers[nextUglyIndex] = min;
            
            while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply2;
            while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply3;
            while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply5;
            
            ++nextUglyIndex;
        }
        
        int ugly = pUglyNumbers[nextUglyIndex - 1];
        delete[] pUglyNumbers;
        
        return ugly;
    }
    
    int Min(int number1, int number2, int number3)
    {
        int min = (number1 < number2) ? number1 : number2;
        min = (min < number3) ? min : number3;
        
        return min;
    }
};

/*
// 动态规划，后面的丑数由前一个丑数乘以 2、3、5 中的一个得来。 
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        if(index == 1)
            return 1;
        
        vector<int> res(index);
        res[0] = 1;
        
        int t2 = 0, t3 = 0, t5 = 0;
        for(int i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if(res[i] == res[t2] * 2)
                t2++;
            if(res[i] == res[t3] * 3)
                t3++;
            if(res[i] == res[t5] * 5)
                t5++;
        }
        
        return res[index - 1];
    }
};

*/ 
