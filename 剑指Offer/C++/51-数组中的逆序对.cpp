/*
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե����� P������ P �� 1000000007 ȡģ�Ľ������������ P % 1000000007��
���磬������{7��5��6��4}�У�һ������ 5 ������ԣ��ֱ��ǣ�7��6������7��5������7��4������6��4���ͣ�5��4��. 
*/

// �Ȱ�����ָ��������飬ͳ�Ƴ��������ڲ�������Ե���Ŀ��Ȼ����ͳ�Ƴ���������������֮�������Ե���Ŀ��
// �ϲ����������鲢ͳ������ԣ�����ָ��ֱ�ָ�������������ĩβ����ÿ�αȽ�����ָ��ָ������֡�
// �����һ���������е����ִ��ڵڶ����������е����֣��򹹳�����ԣ���������Ե���Ŀ���ڵڶ�����������ʣ�����ֵĸ�����
// �����һ�������е�����С�ڻ���ڵڶ��������е����֣��򲻹�������ԡ�ÿ�αȽϵ�ʱ�����Ƕ��ѽϴ�����ִӺ���ǰ���Ƶ�һ���������飬
// ȷ�����������е������ǵ�������ġ��ڰѽϴ�����ָ��Ƶ���������֮�󣬰Ѷ�Ӧ��ָ����ǰ�ƶ�һλ��������������һ�ֱȽϡ�
// ��ͳ������ԵĹ����У�����Ҫ�����鼰������������Ĺ���ʵ���Ͼ��ǹ鲢����
class Solution {
public:
    int InversePairs(vector<int> data) {
        int length = data.size();
        if(length <= 0)
            return 0;
        
		// �������� copy
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
        
        // i ��ʼ��Ϊǰ������һ�����ֵ��±� 
        int i = start + length;
        // j ��ʼ��Ϊ�������һ�����ֵ��±� 
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
