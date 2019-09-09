# 后序遍历序列的尾元素为根节点，左子树节点的值小于根节点，右子树节点的值大于根节点
# 将序列划分为左子树序列和右子树序列，然后递归

class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if sequence == []:
            return False
        
        length = len(sequence)
        root = sequence[-1]
        
        for i in range(length):
            if sequence[i] > root:
                break
        
        for j in range(i, length):
            if sequence[j] < root:
                return False
        
        left = True
        if i > 0:
            left = self.VerifySquenceOfBST(sequence[:i])
        right = True
        if j < length - 1:
            right = self.VerifySquenceOfBST(sequence[i:length-1])
        
        return left and right