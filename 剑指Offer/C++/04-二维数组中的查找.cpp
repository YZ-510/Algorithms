/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

// 首先选取数组中右上角（也可以选取左下角）的数字，若要查找的数字不在数组的右上角，则每一次都在数组的查找范围中剔除一行或者一列。 
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool found = false;
        
        if(array.size() != 0)
        {
            int row = 0;
            int col = array[0].size() - 1;
            while(row < array.size() && col >= 0)
            {
                if(array[row][col] == target)
                {
                    found = true;
                    break;
                }
                else if(array[row][col] > target)
                    --col;
                else
                    ++row;
            }
        }
        
        return found;
    }
};
