/*
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ��� abc,���ӡ�����ַ� a,b,c �������г����������ַ��� abc,acb,bac,bca,cab��cba��
*/ 

// �ݹ飬�������ַ��������п��Կ�����������һ�������п��ܳ����ڵ�һ��λ�õ��ַ������ѵ�һ��λ�õ��ַ��ͺ������е��ַ�������
// �ڶ����̶���һ���ַ�������������ַ������У��Ѻ���ĵ����е��ַ��ֳ������֣������ַ��ĵ�һ���ַ����Լ�����ַ�֮��������ַ��� 
// Ȼ��ѵ�һ���ַ���һ����������ַ������� 
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty())
            return res;
        
        Permutation(str, res, 0);
        
        // ��ʱ res �����в������ֵ�����Ҫ������������
        sort(res.begin(), res.end());
        
        return res;
    }
    
    void Permutation(string str, vector<string> & res, int begin)
    {
        if(begin == str.size() - 1)	// �ݹ���������������Ѿ�ָ�� str ���һ��Ԫ��ʱ 
        {
            if(find(res.begin(), res.end(), str) == res.end())
            	// ��� res �в����� str ����ӣ����� aa �� aa �ظ���ӵ���� 
                res.push_back(str);
        }
        else
        {
        	
            for(int i = begin; i < str.size(); ++i)
            {
                swap(str[i], str[begin]);
                Permutation(str, res, begin + 1);
                swap(str[i], str[begin]);	// ��λ�����Իָ�֮ǰ�ַ�����˳�򣬴ﵽ��һ��λ�õ��ַ�һ�θ�����λ�ý�����Ŀ�� 
            }
        }
    }
    
    void swap(char &fir, char &sec)
    {
        char temp = fir;
        fir = sec;
        sec = temp;
    }
};
