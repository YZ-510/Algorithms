
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        if array == []:
            return []
        
        result = []
        hashmap = {}
        for i in array:
            if i in hashmap:
                hashmap[i] += 1
            else:
                hashmap[i] = 1
        for k in hashmap.keys():
            if hashmap[k] == 1:
                result.append(k)
        
        return result


# 位运算异或：两个相同的数字异或等于，一个数字和 0 异或还是它本身。
# 异或数组中的每个数字，得到的结果就是只出现一次的两个数字的异或结果，
# 在结果中找到第一个为 1 的位的位置，根据该位置是不是 1 把原数组分成两个子数组，
# 每个子数组都包含一个只出现一次的数字，分别进行异或

class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        if array == []:
            return []
        xor = 0
        for i in array:
            xor ^= i
        
        idxOf1 = self.getFirstIdx(xor)
        num1 = num2 = 0
        for j in range(len(array)):
            if self.IsBit(array[j], idxOf1):
                num1 ^= array[j]
            else:
                num2 ^= array[j]
        return [num1, num2]
    
    def getFirstIdx(self, num):
        idx = 0
        while num & 1 == 0 and idx <= 32:
            idx += 1
            num = num >> 1
        return idx
    
    def IsBit(self, num, indexBit):
        num = num >> indexBit
        return num & 1