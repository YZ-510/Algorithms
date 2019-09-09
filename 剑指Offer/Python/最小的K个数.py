
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        tinput = sorted(tinput)
        if tinput == [] or len(tinput) < k:
            return []
        
        return tinput[:k]