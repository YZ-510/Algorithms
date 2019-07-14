/*
���˿���������� 5 ���ƣ��ж��ǲ���һ��˳�ӣ����� 5 �����ǲ��������ġ�
2~10 Ϊ���ֱ���A Ϊ 1�� J Ϊ 11�� Q Ϊ 12�� K Ϊ 13������С�����Կ����������֡� 
*/

// �� 5 ���ƿ����� 5 ��������ɵ����飬��С������������֣������Ƕ�����Ϊ 0��
// �ж� 5 �������ǲ��������ģ���ֱ�۵ķ����ǰ���������
// ���Ȱ������������ͳ�������� 0 �ĸ��������ͳ������֮�����������������֮��Ŀ�ȱ������
// �����ȱ������С�ڻ��ߵ��� 0 �ĸ�������ô���������������ġ�
// ��������еķ� 0 �����ظ����֣�������鲻�������ġ�
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return false;
        
		// ��������
        sort(numbers.begin(),numbers.end());
        
        int numberOfZero = 0;
        int numberOfGap = 0;
        int length = numbers.size();
        
        // ͳ�������� 0 �ĸ���
        for(int i = 0; i < length && numbers[i] == 0; ++i)
            ++numberOfZero;
        
        // ͳ�������еļ����Ŀ
        int small = numberOfZero;
        int big = small + 1;
        while(big < length)
        {
            // ������������ȣ��ж��ӣ��Ͳ�������˳��
            if(numbers[small] == numbers[big])
                return false;
            
            numberOfGap += numbers[big] - numbers[small] - 1;
            small = big;
            ++big;
        }
        
        return (numberOfGap > numberOfZero) ? false : true;
    }
};
