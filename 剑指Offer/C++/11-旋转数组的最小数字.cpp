/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء�
�������� {3,4,5,1,2} Ϊ {1,2,3,4,5} ��һ����ת�����������СֵΪ 1��
NOTE������������Ԫ�ض����� 0���������СΪ 0���뷵�� 0��
*/

// ˫ָ�룬�ֱ�ָ������ĵ�һ��Ԫ�غ����һ��Ԫ�أ��ҵ������м��Ԫ�ء� 
// ������м�Ԫ��λ��ǰ��ĵ��������飬��ô��Ӧ�ô��ڻ��ߵ��ڵ�һ��ָ��ָ���Ԫ�أ���ʱ��С��Ԫ��Ӧ��λ�ڸ��м�Ԫ�صĺ��棻
// ����м�Ԫ��λ�ں���ĵ��������飬��ô��Ӧ��С�ڻ��ߵ��ڵڶ�ָ��ָ���Ԫ�أ���ʱ��С��Ԫ��Ӧ��λ�ڸ��м�Ԫ�ص�ǰ�档 
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        // �����������������ǰ��� 0 ��Ԫ�ذᵽĩβ�����������鱾�� 
        while(rotateArray[left] >= rotateArray[right])
        {
            if(right - left == 1)
            {
                mid = right;
                break;
            }
            
            mid = (left + right) / 2;
            
            // ����±�Ϊ left��right �� mid ָ�������������ȣ���ֻ��˳�����
            if(rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left])
                return MinInOrder(rotateArray, left, right);
            
            if(rotateArray[mid] >= rotateArray[left])
                left = mid;
            else if(rotateArray[mid] <= rotateArray[right])
                right = mid;
        }
        
        return rotateArray[mid];
    }
    
    int MinInOrder(vector<int> &nums, int left, int right)
    {
        int result = nums[left];
        for(int i = left + 1; i <= right; ++i)
        {
            if(result > nums[i])
                result = nums[i];
        }
        
        return result;
    }
};
