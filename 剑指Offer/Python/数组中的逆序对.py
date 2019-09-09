# 原数组排序，遍历排序数组相当于每次取出最小的数字，它在原数组中的位置表示有多少比它大的数在它前面，
# 每次从排序数组中取出一个数就从原数组中删除该数字，保证后面取出的数在原数组中是最小的

class Solution:
    def InversePairs(self, data):
        # write code here
        count = 0
        copy = []
        for i in data:
            copy.append(i)
        copy.sort()
        
        for i in range(len(copy)):
            count += data.index(copy[i])
            data.remove(copy[i])
        
        return count % 1000000007