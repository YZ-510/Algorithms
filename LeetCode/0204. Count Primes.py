# 计数质数
# https://leetcode-cn.com/problems/count-primes/

class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        isPrime = [True] * n
        i = 2
        while i * i < n:
            if isPrime[i]:
                j = i * i
                while j < n:
                    isPrime[j] = 0
                    j += i
            i += 1
        return sum(isPrime[2:])
        
        '''
        if n < 3:
            return 0
        primes = [True] * n
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                primes[i * i: n: i] = [False] * len(primes[i * i: n: i])
        return sum(primes[2:])
        '''