
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here
        if numbers == []:
            return False
        
        numset = set()
        for i in numbers:
            if i in numset:
                duplication[0] = i
                return True
            else:
                numset.add(i)
        
        return False


# 数组中的数字都是在 0~n-1 的范围内，如果数组中没有重复的数字，那么当数组排序之后数字 i 将会出现在下标为 i 的位置
# 重排数组，当扫描到下标为 i 的数字时。比较这个数字 m 是不是等于 i。
# 如果不是，就拿它和第 m 个数字比较。如果它和第 m 个数字相等，就找到了一个重复的数字。
# 如果它和第 m 个数字不相等，就把第 i 个数字和第 m 个数字交换，把 m 放到属于它的位置，继续重复这个比较
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here
        if numbers == []:
            return False
        
        for i in numbers:
            if i < 0 or i > len(numbers) - 1:
                return False
        
        for i in range(len(numbers)):
            while numbers[i] != i:
                if numbers[i] == numbers[numbers[i]]:
                    duplication[0] = numbers[i]
                    return True
                else:
                    idx = numbers[i]
                    numbers[i], numbers[idx] = numbers[idx], numbers[i]
        
        return False