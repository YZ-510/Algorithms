# f(n) = f(n-1) + f(n-2)
# n>2 时，第一次跳 1 级，此时跳法的数目等于后面剩下的 n-1 级台阶的跳法
# 第一次跳 2 级，此时跳法的数目等于后面剩下的 n-2 级台阶的跳法

class Solution:
    def jumpFloor(self, number):
        # write code here
        temp = [1, 2, 3]
        if number < 4:
            return temp[number - 1]
        for i in range(3, number + 1):
            temp[2] = temp[1] + temp[0]
            temp[0], temp[1] = temp[1], temp[2]
        
        return temp[-1]