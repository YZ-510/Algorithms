# 打乱数组
# https://leetcode-cn.com/problems/shuffle-an-array/

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.array = nums[:]
        self.original = nums[:]

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        self.array = self.original[:]
        return self.array

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        tmp = self.array[:]
        for i in range(len(self.array)):
            remove_idx = random.randrange(len(tmp))
            self.array[i] = tmp.pop(remove_idx)
        return self.array


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()