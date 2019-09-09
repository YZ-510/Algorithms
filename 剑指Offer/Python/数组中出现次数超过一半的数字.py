# 出现次数超过数组长度的一半的数字，也就是它比其他所有数字出现次数的和还要多。
# 保存两个值：数组中的数字和它的出现次数，下一个数字等于该数字，次数加 1；如果不等于，次数减 1
# 当次数为 0 时，保存下一个数字，并把次数设为 1。
# 要找的数字一定是最后一次把次数设为 1 时对应的数字

class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        if numbers == []:
            return 0
        length = len(numbers)
        result = numbers[0]
        times = 1
        for i in range(1, length):
            if times == 0:
                result = numbers[i]
                times = 1
            elif numbers[i] == result:
                times += 1
            else:
                times -= 1
        
        if not self.CheckMoreThanHalf(numbers, result, length):
            return 0
        
        return result
    
    def CheckMoreThanHalf(self, numbers, number, length):
        times = 0
        for i in range(length):
            if numbers[i] == number:
                times += 1
        if times * 2 <= length:
            return False
        return True