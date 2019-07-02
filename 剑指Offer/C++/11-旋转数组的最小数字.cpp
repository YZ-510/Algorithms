/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组 {3,4,5,1,2} 为 {1,2,3,4,5} 的一个旋转，该数组的最小值为 1。
NOTE：给出的所有元素都大于 0，若数组大小为 0，请返回 0。
*/

// 双指针，分别指向数组的第一个元素和最后一个元素，找到数组中间的元素。 
// 如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素，此时最小的元素应该位于该中间元素的后面；
// 如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二指针指向的元素，此时最小的元素应该位于该中间元素的前面。 
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        // 特例：把排序数组的前面的 0 个元素搬到末尾，即排序数组本身。 
        while(rotateArray[left] >= rotateArray[right])
        {
            if(right - left == 1)
            {
                mid = right;
                break;
            }
            
            mid = (left + right) / 2;
            
            // 如果下标为 left、right 和 mid 指向的三个数字相等，则只能顺序查找
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
