/*
输入 n 个整数，找出其中最小的 K 个数。
例如输入 4, 5, 1, 6, 2, 7, 3, 8 这 8 个数字，则最小的 4 个数字是 1, 2, 3, 4。
*/ 

// 最大堆中根节点的值总是大于它的子树中任意节点的值，每次可以在 O(1) 时间内得到已有的 k 个数字中的最大值，
// 但需要 O(logk) 时间完成删除及插入操作，设用于从海量的数据中找出最小的 k 个数字。
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int length = input.size();
        vector<int> res;
        if(length <= 0 || k > length || k <= 0)
            return res;
        
        for(int i = 0; i < k; ++i)
            res.push_back(input[i]);
        // 建堆，默认生成最大堆 
        make_heap(res.begin(), res.end());
        
        for(int i = k; i < length; ++i)
        {
            if(input[i] < res[0])
            {
            	// 先弹出堆顶元素，再从容器中删除 
                pop_heap(res.begin(), res.end());
                res.pop_back();
                // 先在容器中加入元素，再调用 push_heap 向堆中插入一个元素 
                res.push_back(input[i]);
                push_heap(res.begin(), res.end());
            }
        }
        // 使其从小到大输出 
        sort_heap(res.begin(), res.end());
        
        return res;
    }
};
