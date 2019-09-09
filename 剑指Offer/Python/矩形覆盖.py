# f(n) = f(n-1) + f(n-2)

class Solution:
    def rectCover(self, number):
        # write code here
        temp = [1, 2, 3]
        if number == 0:
            return 0
        if number < 3:
            return temp[number-1]
        for i in range(3, number + 1):
            temp[2] = temp[1] + temp[0]
            temp[0], temp[1] = temp[1], temp[2]
        
        return temp[-1]