/*
用两个栈来实现一个队列，完成队列的 Push 和 Pop 操作。 队列中的元素为 int 类型。
*/

// 当 stack2 不为空时，在 stack2 中的栈顶元素是最先进入队列的元素，可以弹出；
// 当 stack2 为空时，把 stack1 中的元素逐个弹出并压入 stack2。 
class Solution
{
public:
    void push(int node) {
         stack1.push(node);
    }

    int pop() {
        int data;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        
        data = stack2.top();
        stack2.pop();
        
        return data;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
