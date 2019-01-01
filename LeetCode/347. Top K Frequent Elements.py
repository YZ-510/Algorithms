# 前 K 个高频元素
# https://leetcode-cn.com/problems/top-k-frequent-elements/

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # 先把对应的数字和其出现频次放到 maps 里，遍历 maps 的 value，得到列表 buckets
        # buckets 里的元素为：出现频次与索引相等的数字的集合
        # 即 buckets[3] = 1，出现频次为 3 的数字有 1；buckets[2] = [2, 4]，出现频次为 2 的数字有 2、4
        
        res, maps, buckets = [], collections.Counter(nums), ['*'] * (len(nums) + 1)
        
        for key in maps.keys():
            count = maps.get(key)
            if buckets[count] == '*':
                buckets[count] = []
            buckets[count].append(key)
        i = len(nums)
        while len(res) < k and i >= 0:
            if buckets[i] != '*':
                res.extend(buckets[i])
            i -= 1
        return res