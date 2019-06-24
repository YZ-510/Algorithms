/*
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡� 
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
            
            // ���԰Ѵ�ӡһȦ��Ϊ�Ĳ���ÿһ��������ʼ�������ֹ������һ��ѭ����ӡ 
			// �����Ҵ�ӡһ��
            for(int i = start; i <= endX; ++i)
                res.push_back(matrix[start][i]);
            
            // ���ϵ��´�ӡһ�� 
            if(start < endY)
            {
                for(int i = start + 1; i <= endY; ++i)
                    res.push_back(matrix[i][endX]);
            }
            
            // ���ҵ����ӡһ��
            if(start < endX && start < endY)
            {
                for(int i = endX - 1; i >= start; --i)
                    res.push_back(matrix[endY][i]);
            }
            
            // ���µ��ϴ�ӡһ��
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
