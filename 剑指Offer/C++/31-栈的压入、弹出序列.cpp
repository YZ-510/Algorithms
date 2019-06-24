/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列 1,2,3,4,5 是某栈的压入顺序，
序列 4,5,3,2,1 是该压栈序列对应的一个弹出序列，但 4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/ 

// 建立一个辅助栈，把输入的第一个序列中的数字一次压入该辅助栈，并按照第二个序列的顺序依次从该栈中弹出数字。
// 如果下一个弹出的数字刚好是栈顶数字，那么直接弹出；
// 如果下一个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈，
// 直到把下一个需要弹出的数字压入栈顶为止；
// 如果所有数字都压入栈后仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列。 
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty())
            return false;
        
        stack<int> stackData;
        int index = 0;
        for(int i = 0; i < popV.size(); ++i)
        {
        	// 当辅助栈的栈顶元素不是要弹出的元素时，先压入一些数字入栈 
            while(stackData.empty() || stackData.top() != popV[i])
            {
                stackData.push(pushV[index++]);
                // 如果所有数字都压入辅助栈了，仍没有找到下一个弹出的数字
                if(index == pushV.size() && stackData.top() != popV[i])
                    return false;
            }
			
            stackData.pop();
        }
        
        if(stackData.empty())
            return true;
        else
            return false;
    }
};
