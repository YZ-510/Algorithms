/*
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
求所有子数组的和的最大值，要求时间复杂度为 O(n)。 
*/ 

// 遍历数组，从头到尾逐个累加数组中的数字，若此前累加和小于 0，抛弃重新累加 
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        
        int nCurSum = 0;
        int result = array[0];	// result 存储最大和，不能初始化为 0，存在最大和为负数 
        
        for(int i = 0; i < array.size(); ++i)
        {
            if(nCurSum <= 0)
                nCurSum = array[i];
            else
                nCurSum += array[i];
            
            if(nCurSum > result)
                result = nCurSum;
        }
        
        return result;
    }
};

/*
动态规划，用递归的方式分析动态规划问题，但最终都会基于循环去编码。 
用函数 f(i) 表示以第 i 个数字结尾的子数组的最大和，那么我们需要求出 max(f(i))，0 << i << n。
		pData[i]			i=0 或者 f(i-1)<=0
f(i) = 
		f(i-1) + pData[i]	i>=0 且 f(i-1)>0
当以第 i-1 个数字结尾的子数组中所有数字的和小于 0 时，把这个负数与第 i 个数累加，则得到的结果比第 i 个数字本身还要小，
所以这种情况下以第 i 个数字结尾的子数组就是第 i 个数字本身；
如果以第 i-1 个数字结尾的子数组中所有数字的和大于 0，则于第 i 个数字累加就得到以第 i 个数字结尾的子数组中所有数字的和。
对应的代码与上面的代码一致，f(i) 对应的变量是 nCurSum，max(f(i)) 就是 result。 
*/ 
