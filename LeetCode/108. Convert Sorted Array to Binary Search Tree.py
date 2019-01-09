# 将有序数组转换为二叉搜索树
# https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        # nums[n//2] 为中间元素，根节点，nums[:mid] 为左子树，nums[mid+1:]为右子树
        
        if not nums or len(nums) == 0:
            return None
        root = TreeNode(nums[len(nums) // 2])
        root.left = self.sortedArrayToBST(nums[:len(nums) // 2])
        root.right = self.sortedArrayToBST(nums[len(nums) // 2 + 1:])
        return root