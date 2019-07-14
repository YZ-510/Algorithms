/*
输入一个正数 s，打印出所有和为 s 的连续正数序列（至少含有两个数字）。
*/

// 双指针，用 phigh、plow 分别表示序列的最大值和最小值，首先把 plow 初始化为 1，phigh 初始化为 2。
// 如果从 plow 到 phigh 的序列的和大于 s，则可以从序列中去掉较小的值，也就是增大 plow 的值；
// 如果从 plow 到 phigh 的序列的和小于 s，则可以增大 phigh，让这个序列包含更多的数字。
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        
        int phigh = 2;
        int plow = 1;
        
        while(phigh > plow)
        {
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            if(cur < sum)
                phigh++;
            
            if(cur == sum)
            {
            	// 若序列和正好等于 sum，再增加 phigh，重复前面的过程 
                vector<int> temp;
                for(int i = plow; i <= phigh; ++i)
                    temp.push_back(i);
                res.push_back(temp);
                plow++;
            }
            
            if(cur > sum)
                plow++;
        }
        
        return res;
    }
};
