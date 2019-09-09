# dict 存储当前出现的字符及出现的次数，list 存储当前出现的字符
# 比较 list 的第一个字符和 dict 中出现的次数

class Solution:
    def __init__(self):
        self.dic = {}
        self.lis = []
    # 返回对应char
    
    def FirstAppearingOnce(self):
        # write code here
        while len(self.lis) > 0 and self.dic[self.lis[0]] != 1:
            self.lis.pop(0)
        if len(self.lis) == 0:
            return '#'
        else:
            return self.lis[0]
    
    def Insert(self, char):
        # write code here
        if char not in self.dic.keys():
            self.dic[char] = 1
            self.lis.append(char)
        else:
            self.dic[char] += 1