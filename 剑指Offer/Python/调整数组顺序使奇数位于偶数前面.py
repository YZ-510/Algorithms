# 保证奇数和奇数，偶数和偶数之间的相对位置不变

class Solution:
    def reOrderArray(self, array):
        # write code here
        odd, even = [], []
        for i in array:
            odd.append(i) if i % 2 == 1 else even.append(i)
        
        return odd +even