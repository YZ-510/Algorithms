# 可以看成两步，第一步求所有可能出现在第一个位置的字符，即把第一个字符和后面所有的字符交换；
# 第二步固定第一个字符，求后面所有字符的排列，仍把后面的所有字符分成两部分：后面字符的第一个
# 字符，以及这个字符之后的所有字符，然后把第一个字符逐一和它后面的字符交换

class Solution:
    def Permutation(self, ss):
        # write code here
        if not ss:
            return []
        if len(ss) == 1:
            return list(ss)
        
        charList = list(ss)
        charList.sort()
        pStr = []
        for i in range(0, len(charList)):
            if i > 0 and charList[i] == charList[i-1]:
                continue
            temp = self.Permutation(''.join(charList[:i]) + ''.join(charList[i+1:]))
            for j in temp:
                pStr.append(charList[i] + j)
        
        return pStr