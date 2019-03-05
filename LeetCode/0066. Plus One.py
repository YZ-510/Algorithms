# 加一
# https://leetcode-cn.com/problems/plus-one/

class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        # 倒序逐个判断当前值是否小于 9
        for i in range(len(digits)-1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            else:
                digits[i] = 0
        if i == 0:
            digits.insert(0, 1)
        return digits

        '''
        i = len(digits) - 1
        while digits[i] == 9 and i >= 0:
            digits[i] = 0
            i = i - 1
        if i==-1:
            digits.insert(0, 1)
        else:
            digits[i] = digits[i] + 1
        return digits
        '''
