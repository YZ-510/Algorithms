class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = len(digits) - 1
        while digits[i] == 9 and i >= 0:
            digits[i] = 0
            i = i - 1
        if i==-1:
            digits.insert(0, 1)
        else:
            digits[i] = digits[i] + 1
        return digits