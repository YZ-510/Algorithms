/*
从扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这 5 张牌是不是连续的。
2~10 为数字本身，A 为 1， J 为 11， Q 为 12， K 为 13，而大、小王可以看成任意数字。 
*/

// 把 5 张牌看成由 5 个数字组成的数组，大、小王是特殊的数字，把它们都定义为 0。
// 判断 5 个数字是不是连续的，最直观的方法是把数组排序。
// 首先把数组排序，其次统计数组中 0 的个数，最后统计排序之后的数组中相邻数字之间的空缺总数。
// 如果空缺的总数小于或者等于 0 的个数，那么这个数组就是连续的。
// 如果数组中的非 0 数字重复出现，则该数组不是连续的。
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return false;
        
		// 数组排序
        sort(numbers.begin(),numbers.end());
        
        int numberOfZero = 0;
        int numberOfGap = 0;
        int length = numbers.size();
        
        // 统计数组中 0 的个数
        for(int i = 0; i < length && numbers[i] == 0; ++i)
            ++numberOfZero;
        
        // 统计数组中的间隔数目
        int small = numberOfZero;
        int big = small + 1;
        while(big < length)
        {
            // 相邻两个数相等，有对子，就不可能是顺子
            if(numbers[small] == numbers[big])
                return false;
            
            numberOfGap += numbers[big] - numbers[small] - 1;
            small = big;
            ++big;
        }
        
        return (numberOfGap > numberOfZero) ? false : true;
    }
};
