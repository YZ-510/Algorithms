/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。 
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        int start = 0;
        
        while(columns > start * 2 && rows > start * 2)
        {
            int endX = columns - 1 - start;
            int endY = rows - 1 - start;
            
            // 可以把打印一圈分为四步，每一步根据起始坐标和终止坐标用一个循环打印 
			// 从左到右打印一行
            for(int i = start; i <= endX; ++i)
                res.push_back(matrix[start][i]);
            
            // 从上到下打印一列 
            if(start < endY)
            {
                for(int i = start + 1; i <= endY; ++i)
                    res.push_back(matrix[i][endX]);
            }
            
            // 从右到左打印一行
            if(start < endX && start < endY)
            {
                for(int i = endX - 1; i >= start; --i)
                    res.push_back(matrix[endY][i]);
            }
            
            // 从下到上打印一列
            if(start < endX && start < endY - 1)
            {
                for(int i = endY - 1; i >= start + 1; --i)
                    res.push_back(matrix[i][start]);
            }
            
            ++start;
        }
        
        return res;
    }
};
