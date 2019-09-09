# f(n) = 2 * f(n-1), n >= 2
# f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + ... + f(n-(n-1)) + f(n-n) = f(n-1) + f(n-1)
# f(n-1) = f(n-1-1) + f(n-1-2) + f(n-1-3) + ... + f(n-1-(n-2)) + f(n-1-(n-1))
# f(n-1) 表示第一次跳 1 级后面的跳法

class Solution:
    def jumpFloorII(self, number):
        # write code here
        if number < 2:
            return number
        ans = 1
        for i in range(2, number+1):
            ans = ans * 2
        
        return ans