# 颠倒二进制位
# https://leetcode-cn.com/problems/reverse-bits/

class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        return int(bin(n)[2:].zfill(32)[::-1], 2)
        
        '''
        res = 0
        for _ in range(32):
            res = (res << 1) + n % 2
            n >>= 1
        return res        
        '''