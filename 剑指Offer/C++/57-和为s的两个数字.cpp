/*
输入一个递增排序的数组和一个数字 s，在数组中查找两个数，使得他们的和正好是 s。
如果有多对数字的和等于 s，输出两个数的乘积最小的。
*/ 

// 首尾两个指针，数组是递增排序的，如果二者之和大于 s，尾指针向前移动；如果小于 s，头指针向后移动。
// 两个指针距离越远，乘积越小
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int length = array.size();
        if(length <= 1)
            return res;
        
        int start = 0;
        int end = length - 1;
        
        while(start < end)
        {
            if(array[start] + array[end] == sum)
            {
                res.push_back(array[start]);
                res.push_back(array[end]);
                break;
            }
            else if(array[start] + array[end] < sum)
                start++;
            else
                end--;
        }
        
        return res;
    }
};
