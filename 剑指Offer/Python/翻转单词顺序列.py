# 先翻转整个字符串，再翻装单词
# 遍历字符串，遇到空格，就把空格前的字符串翻装，添加空格，继续遍历

class Solution:
    def ReverseSentence(self, s):
        # write code here
        if len(s) == 0:
            return s
        
        lis = list(s)
        lis = self.Reverse(lis)
        start = 0
        end = 0
        res = ''
        lisTmp = []
        while end < len(lis):
            if end == len(lis) - 1:
                lisTmp.append(self.Reverse(lis[start:]))
                break
            if lis[start] == ' ':
                start += 1
                end += 1
                lisTmp.append(' ')
            elif lis[end] == ' ':
                lisTmp.append(self.Reverse(lis[start:end]))
                start = end
            else:
                end += 1
        for i in lisTmp:
            res += ''.join(i)
        
        return res
    
    def Reverse(self, lis):
        start = 0
        end = len(lis) - 1
        while start < end:
            lis[start], lis[end] = lis[end], lis[start]
            start += 1
            end -= 1
        
        return lis


class Solution:
    def ReverseSentence(self, s):
        # write code here
        if len(s) == 0:
            return s
        ls = s.split(' ')
        ls.reverse()
        
        return ' '.join(ls)