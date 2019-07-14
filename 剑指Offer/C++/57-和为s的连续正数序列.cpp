/*
����һ������ s����ӡ�����к�Ϊ s �������������У����ٺ����������֣���
*/

// ˫ָ�룬�� phigh��plow �ֱ��ʾ���е����ֵ����Сֵ�����Ȱ� plow ��ʼ��Ϊ 1��phigh ��ʼ��Ϊ 2��
// ����� plow �� phigh �����еĺʹ��� s������Դ�������ȥ����С��ֵ��Ҳ�������� plow ��ֵ��
// ����� plow �� phigh �����еĺ�С�� s����������� phigh����������а�����������֡�
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        
        int phigh = 2;
        int plow = 1;
        
        while(phigh > plow)
        {
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            if(cur < sum)
                phigh++;
            
            if(cur == sum)
            {
            	// �����к����õ��� sum�������� phigh���ظ�ǰ��Ĺ��� 
                vector<int> temp;
                for(int i = plow; i <= phigh; ++i)
                    temp.push_back(i);
                res.push_back(temp);
                plow++;
            }
            
            if(cur > sum)
                plow++;
        }
        
        return res;
    }
};
