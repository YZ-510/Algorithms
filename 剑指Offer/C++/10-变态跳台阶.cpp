/*
一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级……它也可以跳上 n 级。
求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
*/

// f(n) = f(n-1) * 2，n > 1; f(1) = 1
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0)
            return -1;
        
        vector<int> res;
        res.push_back(1);
        
        for(int i = 1; i < number; ++i)
            res.push_back(res.back() * 2);	// back() 得到 vector 最后一个数据的引用
        
        return res.back();
    }
};
