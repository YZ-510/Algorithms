/*
��ֻ���������� 2��3 �� 5��������������Ugly Number�������� 6��8 ���ǳ������� 14 ���ǣ���Ϊ������������ 7��
ϰ�������ǰ� 1 �����ǵ�һ���������󰴴�С�����˳��ĵ� N ��������
*/

/* 
��˳���ÿ���������������У�����һ��������ÿ����������ǰ��ĳ������� 2��3 ���� 5 �õ��ġ�
���������ĳ������� M���ó����϶���ǰ��ĳһ���������� 2��3 ���� 5 �Ľ����
�����������ȿ��ǰ����е�ÿ���������� 2��С�ڻ��ߵ��� M �϶��Ѿ����������ˣ�
����Ҫ�ٴο��ǣ�����õ����ɴ��� M �Ľ�� ��������ֻ��Ҫ��һ������ M �Ľ����
��Ϊ����ϣ�������ǰ���С�����˳�����ɵġ����ڳ��� 2 ���ԣ��϶�����ĳһ������ T2��
������֮ǰ��ÿ���������� 2 �õ��Ľ������С���������ĳ���������֮��ĳ������� 2 �õ��Ľ������̫��
ֻ��������������λ�ã�ͬʱÿ�������µĳ�����ʱ��ȥ������� T2 ���ɡ� 
���ڳ��� 3 �� 5 ���ԣ�Ҳ����ͬ���� T3 �� T5����ô��һ������Ӧ���� T2 * 2��T3 * 3 �� T5 * 5 �� 3 ��������С�ߡ� 
*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        
        int *pUglyNumbers = new int[index];
        pUglyNumbers[0] = 1;
        int nextUglyIndex = 1;
        
        int *pMultiply2 = pUglyNumbers;
        int *pMultiply3 = pUglyNumbers;
        int *pMultiply5 = pUglyNumbers;
        
        while(nextUglyIndex < index)
        {
            int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
            pUglyNumbers[nextUglyIndex] = min;
            
            while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply2;
            while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply3;
            while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply5;
            
            ++nextUglyIndex;
        }
        
        int ugly = pUglyNumbers[nextUglyIndex - 1];
        delete[] pUglyNumbers;
        
        return ugly;
    }
    
    int Min(int number1, int number2, int number3)
    {
        int min = (number1 < number2) ? number1 : number2;
        min = (min < number3) ? min : number3;
        
        return min;
    }
};

/*
// ��̬�滮������ĳ�����ǰһ���������� 2��3��5 �е�һ�������� 
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        if(index == 1)
            return 1;
        
        vector<int> res(index);
        res[0] = 1;
        
        int t2 = 0, t3 = 0, t5 = 0;
        for(int i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if(res[i] == res[t2] * 2)
                t2++;
            if(res[i] == res[t3] * 3)
                t3++;
            if(res[i] == res[t5] * 5)
                t5++;
        }
        
        return res[index - 1];
    }
};

*/ 
