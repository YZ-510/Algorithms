/*
ͳ��һ�����������������г��ֵĴ�����
*/ 

// �ö��ֲ���ֱ���ҵ���һ�� k �����һ�� k
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        
        int number = 0;
        int length = data.size();
        
        int firstK = GetFirstK(data, k, 0, length - 1);
        int lastK = GetLastK(data, k, 0, length - 1);
        
        if(firstK > -1 && lastK > -1)
            number = lastK - firstK + 1;
        
        return number;
    }
    
    // �ݹ� 
    int GetFirstK(vector<int> data, int k, int start, int end)
    {
        if(start > end)
            return -1;
        
        int mid = (start + end) / 2;
        if(data[mid] == k)
        {
        	// ����м�����ֵ��� k���ж�ǰ��һ�������ǲ��� k
            if((mid > 0 && data[mid - 1] != k) || mid == 0)
                return mid;
            else
                return GetFirstK(data, k, start, mid - 1);	// ��ǰ�������Ҳ�� k�����һ�� k �϶��������ǰ��� 
        }
        else if(data[mid] > k)
            return GetFirstK(data, k, start, mid - 1);
        else
            return GetFirstK(data, k, mid + 1, end);
    }
    
    // ѭ�� 
    int GetLastK(vector<int> data, int k, int start, int end)
    {
        if(start > end)
            return -1;
        
        int mid = (start + end) / 2;
        while(start <= end)
        {
            if(data[mid] == k)
            {
            	// �ж��ǲ������һ�� k��Ҳ������һ�������ǲ��� k 
                if((mid < end && data[mid + 1] != k) || mid == end)
                    return mid;
                else
                    start = mid + 1;
            }
            else if(data[mid] < k)
                start = mid + 1;
            else
                end = mid - 1;
            
            mid = (start + end) / 2;
        }
        
        return - 1;
    }
};
