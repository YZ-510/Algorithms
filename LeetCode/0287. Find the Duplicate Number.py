# 寻找重复数
# https://leetcode-cn.com/problems/find-the-duplicate-number/

class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 二分查找，使用鸽笼原理进行检验
        # 根据鸽笼原理，给定 n+1 个范围为 [1, n] 的整数，其中一定存在数字出现至少两次
        # 遍历数组，统计小于等于 mid 的数字个数 count
        # 如果 count 小于等于 mid，说明 1 ~ mid 这些数字中没有重复项，重复项在右半边 mid ~ n
        # 如果 count 大于 mid，说明 1 ~ mid 这些数字中有重复项，缩小到左半边继续搜索
        # 时间复杂度：O(NlgN)，空间复杂度：O(1)
        
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            count = sum(num <= mid for num in nums)
            if count > mid:
                right = mid - 1
            else:
                left = mid + 1
        return left        
        
        '''
        # 快慢指针，时间复杂度：O(N)，空间复杂度：O(1)
        # 把数组抽象成链表，链表成环，类似 142.Linked List Cycle II
        # 因为有重复数字，那么指针在移动过程中一定会因为这个重复数字反复的经过某一条路径，这个路径就是所谓链表的环
        
        slow, fast = 0, 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        finder = 0
        while True:
            slow = nums[slow]
            finder = nums[finder]
            if slow == finder:
                return slow
        '''
