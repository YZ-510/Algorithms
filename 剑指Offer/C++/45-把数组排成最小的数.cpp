/*
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
���磬��������{ 3��32��321}�����ӡ���������������ųɵ���С����Ϊ 321323��
*/ 

// �������� m��n����Ҫȷ��һ���ȽϹ����ж� m �� n �ĸ�Ӧ������ǰ�档 
// ��� mn < nm��Ҳ���� m Ӧ������ n ��ǰ�棬���� m С�� n����� nm < mn������ n С�� m��
// �����������ķ������ǰ�����ת�����ַ�������Ƚ� mn �� nm �Ĵ�Сֻ��Ҫ�����ַ�����С�ıȽϹ���Ϳ����ˡ�
// ʱ�临�Ӷ� �� sort ��ʱ�临�Ӷ���ͬ��O(nlogn) 
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty())
            return res;
        
        // �ں��� compare �ж���ȽϹ��򣬵��ÿ⺯�� sort ����
        sort(numbers.begin(), numbers.end(), compare);
        
        // ���ź���������е�����ƴ�ӳ��ַ��� 
        for(int i = 0; i < numbers.size(); ++i)
            res += to_string(numbers[i]);
        
        return res;
    }
    
    static bool compare(int a, int b)
    {
    	// to_string() ���Խ� int ת��Ϊ string 
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        
        return A < B;
    }
};

/*
// ʱ�临�Ӷ� O(n2)
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty())
            return res;
        
        for(int i = 0; i < numbers.size(); ++i)
        {
            for(int j = i + 1; j < numbers.size(); ++j)
            {
                string a = to_string(numbers[i]) + to_string(numbers[j]);
                string b = to_string(numbers[j]) + to_string(numbers[i]);
                // �Ƚ��ַ��� a��b ��С���� a > b��˵�� numbers[j] Ӧ������ numbers[i] ǰ�棬����λ�� 
                if(a > b)
                {
                    int temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }
        
        for(int i = 0; i < numbers.size(); ++i)
            res += to_string(numbers[i]);
        
        return res;
    }
};
*/ 
