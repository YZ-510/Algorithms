/*
����һ������ A[0,1,...,n-1],�빹��һ������ B[0,1,...,n-1],
���� B �е�Ԫ�� B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
*/ 

// �� B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1] ���� A[0]*A[1]*...*A[i-1] �� A[i+1]*...*A[n-1] �����ֵĳ˻���
// ��ˣ����� B ������һ��������������B[i] Ϊ�����е� i ������Ԫ�صĳ˻���
// ���� C[i] = A[0]*A[1]*...*A[i-1]��D[i] = A[i+1]*...*A[n-1]��
// C[i] ���������϶��µ�˳������������ C[i] = C[i-1] * A[i-1]��
// D[i] ���������¶��ϵ�˳������������ D[i] = D[i+1] * A[i+1]��
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        if(A.empty())
            return res;
        
        int length = A.size();
        res.push_back(1);
        // ���� C[i] 
        for(int i = 1; i < length; ++i)
            res.push_back(res.back() * A[i-1]);
        
        int temp = 1;
        // ���� D[i]
        for(int i = length - 1; i > 0; --i)
        {
            temp *= A[i];
            res[i-1] *= temp;
        }
        
        return res;
    }
};
