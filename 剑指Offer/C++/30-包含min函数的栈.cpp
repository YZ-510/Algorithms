/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数。
在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
*/

class Solution {
public:
    void push(int value) {
        // 把新元素压入数据栈
        m_data.push(value);
        
        // 当新元素比之前的最小元素小时，把新元素压入辅助栈；
        // 否则把之前的最小元素重复压入辅助栈
        if(m_min.size() == 0 || value < m_min.top())
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }
    void pop() {
        if(!m_data.empty())
        {
            m_data.pop();
            m_min.pop();
        }
    }
    int top() {
        return m_data.top();
    }
    int min() {
        return m_min.top();
    }
    
private:
    stack<int> m_data; //数据栈，存放栈的所有元素 
    stack<int> m_min; // 辅助栈，存放栈的最小元素
};
