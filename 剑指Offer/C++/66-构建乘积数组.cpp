/*
给定一个数组 A[0,1,...,n-1],请构建一个数组 B[0,1,...,n-1],
其中 B 中的元素 B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]，不能使用除法。
*/ 

// 把 B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1] 看成 A[0]*A[1]*...*A[i-1] 和 A[i+1]*...*A[n-1] 两部分的乘积，
// 因此，数组 B 可以用一个矩阵来创建，B[i] 为矩阵中第 i 行所有元素的乘积。
// 定义 C[i] = A[0]*A[1]*...*A[i-1]、D[i] = A[i+1]*...*A[n-1]，
// C[i] 可以用自上而下的顺序计算出来，即 C[i] = C[i-1] * A[i-1]，
// D[i] 可以用自下而上的顺序计算出来，即 D[i] = D[i+1] * A[i+1]。
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        if(A.empty())
            return res;
        
        int length = A.size();
        res.push_back(1);
        // 计算 C[i] 
        for(int i = 1; i < length; ++i)
            res.push_back(res.back() * A[i-1]);
        
        int temp = 1;
        // 计算 D[i]
        for(int i = length - 1; i > 0; --i)
        {
            temp *= A[i];
            res[i-1] *= temp;
        }
        
        return res;
    }
};
