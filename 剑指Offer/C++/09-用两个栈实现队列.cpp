/*
������ջ��ʵ��һ�����У���ɶ��е� Push �� Pop ������ �����е�Ԫ��Ϊ int ���͡�
*/

// �� stack2 ��Ϊ��ʱ���� stack2 �е�ջ��Ԫ�������Ƚ�����е�Ԫ�أ����Ե�����
// �� stack2 Ϊ��ʱ���� stack1 �е�Ԫ�����������ѹ�� stack2�� 
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
