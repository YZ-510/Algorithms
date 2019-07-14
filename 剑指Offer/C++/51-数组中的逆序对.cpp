/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数 P。并将 P 对 1000000007 取模的结果输出，即输出 P % 1000000007。
例如，在数组{7，5，6，4}中，一共存在 5 个逆序对，分别是（7，6）、（7，5）、（7，4）、（6，4）和（5，4）. 
*/

// 先把数组分隔成子数组，统计出子数组内部的逆序对的数目，然后再统计出两个相邻子数组之间的逆序对的数目。
// 合并连个子数组并统计逆序对：先用指针分别指向两个子数组的末尾，并每次比较两个指针指向的数字。
// 如果第一个子数组中的数字大于第二个子数组中的数字，则构成逆序对，并且逆序对的数目等于第二个子数组中剩余数字的个数；
// 如果第一个数组中的数字小于或等于第二个数组中的数字，则不构成逆序对。每次比较的时候，我们都把较大的数字从后往前复制到一个辅助数组，
// 确保辅助数组中的数字是递增排序的。在把较大的数字复制到辅助数组之后，把对应的指针向前移动一位，接下来进行下一轮比较。
// 在统计逆序对的过程中，还需要对数组及进行排序，排序的过程实际上就是归并排序。
class Solution {
public:
    int InversePairs(vector<int> data) {
        int length = data.size();
        if(length <= 0)
            return 0;
        
		// 辅助数组 copy
        vector<int> copy;
        for(int i = 0; i < length; ++i)
            copy.push_back(data[i]);
        
        long long count = InverParisCore(data, copy, 0, length - 1);
        
        return count % 1000000007;
    }
    
    long long InverParisCore(vector<int> &data, vector<int> &copy, int start, int end)
    {
        if(start == end)
        {
            copy[start] = data[start];
            return 0;
        }
        int length = (end - start) / 2;
        long long left = InverParisCore(copy, data, start, start + length);
        long long right = InverParisCore(copy, data, start + length + 1, end);
        
        // i 初始化为前半段最后一个数字的下标 
        int i = start + length;
        // j 初始化为后半段最后一个数字的下标 
        int j = end;
        int indexcopy = end;
        long long count = 0;
        while(i >= start && j >= start + length + 1)
        {
            if(data[i] > data[j])
            {
                copy[indexcopy--] = data[i--];
                count = count + j - start - length;
            }
            else
                copy[indexcopy--] = data[j--];
        }
        
        for(; i >= start; --i)
            copy[indexcopy--] = data[i];
        for(; j >= start + length + 1; --j)
            copy[indexcopy--] = data[j];
        
        return left + right + count;
    }
};
