/*
统计一个数字在排序数组中出现的次数。
*/ 

// 用二分查找直接找到第一个 k 及最后一个 k
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        
        int number = 0;
        int length = data.size();
        
        int firstK = GetFirstK(data, k, 0, length - 1);
        int lastK = GetLastK(data, k, 0, length - 1);
        
        if(firstK > -1 && lastK > -1)
            number = lastK - firstK + 1;
        
        return number;
    }
    
    // 递归 
    int GetFirstK(vector<int> data, int k, int start, int end)
    {
        if(start > end)
            return -1;
        
        int mid = (start + end) / 2;
        if(data[mid] == k)
        {
        	// 如果中间的数字等于 k，判断前面一个数字是不是 k
            if((mid > 0 && data[mid - 1] != k) || mid == 0)
                return mid;
            else
                return GetFirstK(data, k, start, mid - 1);	// 若前面的数字也是 k，则第一个 k 肯定在数组的前半段 
        }
        else if(data[mid] > k)
            return GetFirstK(data, k, start, mid - 1);
        else
            return GetFirstK(data, k, mid + 1, end);
    }
    
    // 循环 
    int GetLastK(vector<int> data, int k, int start, int end)
    {
        if(start > end)
            return -1;
        
        int mid = (start + end) / 2;
        while(start <= end)
        {
            if(data[mid] == k)
            {
            	// 判断是不是最后一个 k，也就是下一个数字是不是 k 
                if((mid < end && data[mid + 1] != k) || mid == end)
                    return mid;
                else
                    start = mid + 1;
            }
            else if(data[mid] < k)
                start = mid + 1;
            else
                end = mid - 1;
            
            mid = (start + end) / 2;
        }
        
        return - 1;
    }
};
