/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如，输入数组{ 3，32，321}，则打印出这三个数字能排成的最小数字为 321323。
*/ 

// 两个数字 m、n，需要确定一个比较规则判断 m 和 n 哪个应该排在前面。 
// 如果 mn < nm，也就是 m 应该排在 n 的前面，定义 m 小于 n；如果 nm < mn，定义 n 小于 m。
// 解决大数问题的方法就是把数字转换成字符串，则比较 mn 和 nm 的大小只需要按照字符串大小的比较规则就可以了。
// 时间复杂度 和 sort 的时间复杂度相同，O(nlogn) 
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty())
            return res;
        
        // 在函数 compare 中定义比较规则，调用库函数 sort 排序
        sort(numbers.begin(), numbers.end(), compare);
        
        // 把排好序的数组中的数字拼接成字符串 
        for(int i = 0; i < numbers.size(); ++i)
            res += to_string(numbers[i]);
        
        return res;
    }
    
    static bool compare(int a, int b)
    {
    	// to_string() 可以将 int 转化为 string 
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        
        return A < B;
    }
};

/*
// 时间复杂度 O(n2)
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
                // 比较字符串 a、b 大小，若 a > b，说明 numbers[j] 应该排在 numbers[i] 前面，调换位置 
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
