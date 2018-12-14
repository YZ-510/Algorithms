# 二进制求和
# https://leetcode-cn.com/problems/add-binary/

class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        '''
        int() 将一个字符串或数字转换为整型 
        int(x, base) x–字符串或数字, base–进制数，默认十进制
        bin() 函数返回一个整型 int 或者长整数 long int 的二进制表示
        '''
        a, b = int(a, 2), int(b, 2)
        return bin(a + b)[2:]
    
      
        '''
        if a == '' or b == '':
            return a + b
        if a[-1] == '0' and b[-1] == '0':
            return self.addBinary(a[:-1], b[:-1]) + '0'
        elif a[-1] == '1' and b[-1] == '1':
            return self.addBinary(a[:-1], self.addBinary(b[:-1], '1')) + '0'
        else:
            return self.addBinary(a[:-1], b[:-1]) + '1'
        '''