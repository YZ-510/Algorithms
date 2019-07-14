/*
����һ����������������һ������ s���������в�����������ʹ�����ǵĺ������� s��
����ж�����ֵĺ͵��� s������������ĳ˻���С�ġ�
*/ 

// ��β����ָ�룬�����ǵ�������ģ��������֮�ʹ��� s��βָ����ǰ�ƶ������С�� s��ͷָ������ƶ���
// ����ָ�����ԽԶ���˻�ԽС
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int length = array.size();
        if(length <= 1)
            return res;
        
        int start = 0;
        int end = length - 1;
        
        while(start < end)
        {
            if(array[start] + array[end] == sum)
            {
                res.push_back(array[start]);
                res.push_back(array[end]);
                break;
            }
            else if(array[start] + array[end] < sum)
                start++;
            else
                end--;
        }
        
        return res;
    }
};
