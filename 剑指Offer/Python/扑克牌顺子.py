# 首先对数组排序，统计数组中 0 个数，统计排序之后的数组中相邻数字之间的空缺总数
# 如果空缺的总数小于或者等于 0 的个数，数组就是连续的

class Solution:
    def IsContinuous(self, numbers):
        # write code here
        if not numbers or len(numbers) == 0:
            return False
        
        transdict = {'A': 1, 'J': 11, 'Q': 12, 'K': 13}
        for i in range(len(numbers)):
            if numbers[i] in transdict.keys():
                numbers[i] = transdict[numbers[i]]
        
        numbers = sorted(numbers)
        number_0 = 0
        number_gap = 0
        
        for j in range(len(numbers)):
            if numbers[j] == 0:
                number_0 += 1
            elif numbers[j] > 0:
                break
        
        small = number_0
        big = small + 1
        while big < len(numbers):
            if numbers[small] == numbers[big]:
                return False
            number_gap += numbers[big] - numbers[small] - 1
            small = big
            big += 1
        
        return False if number_0 < number_gap else True