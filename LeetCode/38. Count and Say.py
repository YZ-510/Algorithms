class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        '''
        i 代表字符下标，从 0 开始取值，也就是从第一个字符开始，因为要让 i 取到最后一个字符
        并且后面还要进行 i+1 的操作，所以将原字符串随意加上一个 ‘*’ 字符防止溢出
        count 代表此时已经连续相同的字符个数
        res 代表最终输出的字符串

        只要 i 下标对应的字符等于下一个字符，则 count 和 i 都加 1，无限循环
        如果 i 下标对应的字符不等于下一个字符了，则 res 应该加上 str(count) 和 i 下标对应的那个字符，并且 i 加 1，count 复原回 1
        '''
        if n == 1:
            return '1'
        s = self.countAndSay(n-1) + '*'
        res, count = '', 1
        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:
                count += 1
            else:
                res += str(count) + str(s[i])
                count = 1
        return res
        
        '''
        res = '1'
        for i in range(n-1):
            res = ''.join([str(len(list(group))) + digit for digit, group in itertools.groupby(res)])
        return res
        '''