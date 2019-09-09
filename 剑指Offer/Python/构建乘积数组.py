# 把 B[i] = A[0]*A[1]*…*A[i-1]*A[i+1]*…*A[n-1] 看成两部分的乘积，
# C[i] = A[0]*A[1]*…*A[i-1]，C[i] = C[i-1] * A[i-1]
# D[i] = A[i+1]*…*A[n-1]，D[i] = D[i+1] * A[i+1]

class Solution:
    def multiply(self, A):
        # write code here
        if not A or len(A) <= 0:
            return
            
        length = len(A)
        lis = [1] * length
        for i in range(1, length):
            lis[i] = lis[i-1] * A[i-1]
        temp = 1
        for i in range(length-2, -1, -1):
            temp = temp * A[i+1]
            lis[i] *= temp
        
        return lis


class Solution:
    def multiply(self, A):
        # write code here
        if not A:
            return []
        
        B = []
        cur = 1
        for i in range(len(A)):
            for j in range(len(A)):
                if i != j:
                    cur *= A[j]
            B.append(cur)
            cur = 1
        
        return B