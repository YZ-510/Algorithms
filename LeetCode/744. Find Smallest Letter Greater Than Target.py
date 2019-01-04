# 
# https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/

class Solution:
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        for char in letters:
            if char > target:
                return char
        return letters[0]
        
        '''
        left, right = 0, len(letters) - 1
        while left <= right:
            mid = (left + right) // 2
            if letters[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        if left == len(letters):
            left = 0
        return letters[left]        
        '''