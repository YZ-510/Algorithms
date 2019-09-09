# 先翻转整个字符串，再分别翻转 [:len(S)-n] 和 [len(s)-n:]

class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        if len(s) == 0 or n < 0:
            return s
        
        length = len(s)
        n = n % length
        lis = list(s)
        lis = self.Reverse(lis)
        pivot = length - n
        frontlist = self.Reverse(lis[:pivot])
        behindlist = self.Reverse(lis[pivot:])
        
        res = ''
        res = ''.join(frontlist)+ ''.join(behindlist)
        
        return res
    
    def Reverse(self, lis):
        start = 0
        end = len(lis) - 1
        while start < end:
            lis[start], lis[end] = lis[end], lis[start]
            start += 1
            end -= 1
        
        return lis