# 从原字符串末尾开始替换，最后把结果逆序输出即可

class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        if s == None:
            return ''
        
        res = ''
        length = len(s) - 1
        while length >= 0:
            if s[length] == ' ':
                res += '02%'
            else:
                res += s[length]
            length -= 1
        
        return res[::-1]


# 先遍历一遍字符串统计空格的数量，计算出替换之后字符串的总长度
# 从字符串的末尾开始开始复制和替换
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        if s == None:
            return ''
        spaceNum = 0
        for char in s:
            if char == ' ':
                spaceNum += 1
        
        newStrLen = len(s) + spaceNum * 2
        newStr = newStrLen * [None]
        indexOfOriginal, indexOfNew = len(s) - 1, newStrLen - 1
        
        while indexOfNew >= 0 and indexOfOriginal <= indexOfNew:
            if s[indexOfOriginal] == ' ':
                newStr[indexOfNew - 2: indexOfNew + 1] = ['%', '2', '0']
                indexOfNew -= 3
                indexOfOriginal -= 1
            else:
                newStr[indexOfNew] = s[indexOfOriginal]
                indexOfNew -= 1
                indexOfOriginal -= 1
        
        return ''.join(newStr)