/*
地上有一个 m 行和 n 列的方格。一个机器人从坐标 (0, 0) 的格子开始移动，
每一次只能向左、右、上、下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于 k 的格子。 
例如，当 k 为 18 时，机器人能够进入方格（35, 37），因为 3+5+3+7 = 18。
但是，它不能进入方格（35, 38），因为 3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows <= 0 || cols <= 0)
            return 0;
        
        bool *visited = new bool[rows * cols];
        for(int i = 0; i < rows * cols; ++i)
            visited[i] = false;
        
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        
        delete[] visited;
        
        return count;
    }
    
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int count = 0;
        if(check(threshold, rows, cols, row, col, visited))
        {
            visited[row * cols + col] = true;
            
            count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                    + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                    + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                    + movingCountCore(threshold, rows, cols, row, col + 1, visited);
        }
        
        return count;
    }
    
    // 函数 check 判断机器人能否进入坐标为 (row, col) 的方格 
    bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        if(row >= 0 && row < rows && col >= 0 && col < cols
                  && getDigitSum(row) + getDigitSum(col) <= threshold
                  && !visited[row * cols + col])
            return true;
        
        return false;
    }
    
    // 函数 getDigitSum 计算一个数字的数位之和 
    int getDigitSum(int number)
    {
        int sum = 0;
        while(number > 0)
        {
            sum += number % 10;
            number /= 10;
        }
        
        return sum;
    }
};
