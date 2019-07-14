/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小 3，那么一共存在 6 个滑动窗口，它们的最大值分别为{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下 6 个：{[2,3,4],2,6,2,5,1}，{2,[3,4,2],6,2,5,1}，
{2,3,[4,2,6],2,5,1}，{2,3,4,[2,6,2],5,1}，{2,3,4,2,[6,2,5],1}，{2,3,4,2,6,[2,5,1]}。
*/ 

/* 
不把滑动窗口的每个数值都存入队列，而是只把有可能成为滑动窗口最大值的数值存入一个两端开口的队列 - 双端队列 deque。 
队列里存入数字在数组里的下标，而不是数值。当一个数字的下标与当前处理的数字的下标之差大于或者等于滑动窗口的大小时，
这个数字已经从窗口中滑出，可以从队列中删除了。
滑动窗口的最大值总是位于队列的头部。
index 是一个双端开口的队列，用来保存有可能是滑动窗口最大值的数字的下标。在存入一个数字的下标之前，
首先要判断队列里已有数字是否小于待存入的数字。如果已有的数字小于待存入的数字，那么这些数字已经不可能是滑动窗口的最大值，
因此它们将会被依次从队列的尾部删除（pop_back）。同时，如果队列头部的数字已经从窗口里滑出，
那么滑出的数字也需要从队列的头部删除（pop_front）。
*/ 
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> maxInWindows;
        if(num.size() >= size && size >= 1)
        {
            deque<int> index;
            
            // 先把前 size 个数字存入队列，不需要输出滑动窗口的最大值
            for(unsigned int i = 0; i < size; ++i)
            {
            	// 如果当前数字比队列队尾的数字大，说明之前加入的数字不可能是最大值了，因为当前数字比之前数字进入队列更晚
                while(!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();	// 删除比当前数字小的数字的下标
                
                index.push_back(i);	// 队尾存入当前数字下标
            }
            
            // 处理 size 后的数字，需要输出滑动窗口的最大值
            for(unsigned int i = size; i < num.size(); ++i)
            {
                maxInWindows.push_back(num[index.front()]);
                
                // 如果已有的数字小于待存入的数字，那么这些数字已经不可能是滑动窗口的最大值，从队列的尾部删除 pop_back
                while(!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();
                if(!index.empty() && index.front() <= (int)(i - size))	// 判断队首数字是否已经从窗口里滑出
                    index.pop_front();	// 删除队首数字 
                
                index.push_back(i);	// 将当期数字的下标存入队尾，因为有可能成为滑动窗口中的最大值
            }
            maxInWindows.push_back(num[index.front()]);
        }
        
        return maxInWindows;
    }
};
