/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص� min ������
�ڸ�ջ�У����� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��
*/

class Solution {
public:
    void push(int value) {
        // ����Ԫ��ѹ������ջ
        m_data.push(value);
        
        // ����Ԫ�ر�֮ǰ����СԪ��Сʱ������Ԫ��ѹ�븨��ջ��
        // �����֮ǰ����СԪ���ظ�ѹ�븨��ջ
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
    stack<int> m_data; //����ջ�����ջ������Ԫ�� 
    stack<int> m_min; // ����ջ�����ջ����СԪ��
};
