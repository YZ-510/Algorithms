/*
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值； 
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用 Insert()方法读取数据流，使用 GetMedian()方法获取当前读取数据的中位数。
*/ 

// 使用最大堆和最小堆，首先要保证数据平均分配到两个堆中，因此两个堆中数据的数目之差不能超过 1。
// 为了实现平均分配，可以在数据的总数目是偶数时把新数据插入最小堆，否则插入最大堆。
// 还要保证最小堆中的所有数字都大于最大堆中的数字。
// min 为最小堆，max 为最大堆，基于 STL 中的函数 push_heap、pop_heap 及 vector 实现堆， 
// 比较仿函数 less 和 greater 分别用来实现最大堆和最小堆。
class Solution {
public:
    void Insert(int num)
    {
        int size = min.size() + max.size();
        // 数据的总数目是偶数时，把新数据插入最小堆 
        if((size & 1) == 0)
        {
        	// 如果新数据小于最大堆中最大的数，则将该数据插入最大堆，并把最大堆中最大的数字拿出来插入最小堆 
            if(max.size() > 0 && num < max[0])
            {
            	// 数据插入最大堆 
                max.push_back(num);
                // 调整最大堆 
                push_heap(max.begin(), max.end(), less<int>());
                
                num = max[0];
                
                //删除最大堆的堆顶元素 
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            // 数据插入最小堆 
            min.push_back(num);
            // 调整最小堆 
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else
        {
        	// 如果新数据大于最小堆中最小的数，则将该数据插入最小堆，并把最小堆中最小的数字拿出来插入最大堆中 
            if(min.size() > 0 && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                
                num = min[0];
                
                // 删除最小堆的堆顶元素 
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            // 数据插入最大堆 
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    { 
        int size = min.size() + max.size();
        if(size <= 0)
            return 0;
        
        double median;
        if((size & 1) == 1)
            median = min[0];
        else
            median = (min[0] + max[0]) / 2.0;
        
        return median;
    }

private:
    vector<int> min;
    vector<int> max;
};
