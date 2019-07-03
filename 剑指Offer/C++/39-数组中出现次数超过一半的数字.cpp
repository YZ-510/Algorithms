/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为 9 的数组 {1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了 5 次，
超过数组长度的一半，因此输出 2。如果不存在则输出 0。
*/ 

// 遍历数组时保存两个值：一个是数组中的数字，另一个是次数。
// 当遍历到到一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数加 1；
// 如果下一个数字和我们之前保存的数字不同，则次数减 1。如果次数为 0，那么需要保存下一个数字，并把次数设为 1.
// 由于要找的数字出现的次数比其他所有数字出现的次数之和还要多，要找的数字肯定是最后一次把次数设为 1 时对应的数字。 
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); ++i)
        {
            if(times == 0)
            {
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
                times++;
            else
                times--;
        }
        
        // 判断 result 出现次数是否超过数组长度的一半 
        times = 0;
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(numbers[i] == result)
                times++;
        }
        if(times * 2 <= numbers.size())
            return 0;
        
        return result;
    }
};
