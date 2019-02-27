# 数组中两个数的最大异或值
# https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
# 参考：https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91050?page=3

class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        answer = 0
        for i in range(32)[::-1]:
            answer <<= 1
            prefixes = {num >> i for num in nums}
            answer += any(answer^1 ^ p in prefixes for p in prefixes)
        return answer