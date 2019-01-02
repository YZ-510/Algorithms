# 找到 K 个最接近的元素
# https://leetcode-cn.com/problems/find-k-closest-elements/

class Solution:
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        # 二分查找
        # 比较区间两端与 x 的距离，即 mid 位置元素和 x 的距离跟 mid+k 位置元素和 x 的距离
        # 如果左边距离远，向右边走；如果右边距离远，向左边走
        
        left = 0
        right = len(arr) - k
        while left < right:
            mid = (left + right) // 2
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid
        return arr[left : left + k]
        
        '''
        # 双指针
        # 数组有序，实际上相当于返回原数组的一个长度为 k 的子数组，去掉 len(arr)-k 个元素
        # 去掉的顺序肯定是从两头开始，因为距离 x 最远的数字肯定在首尾出现
        # 从左右两个方向向中间遍历，每次把距离大的元素移除，最后保留 k 个元素
        
        while len(arr) > k:
            if x - arr[0] <= arr[-1] - x:
                arr.pop()
            else:
                arr.pop(0)
        return arr        
        '''
        
        '''
        # 堆，时间复杂度：O(N)，空间复杂度：O(N)
        # 计算每个元素和 x 的距离，找出最近距离的元素
        # heapq.heapify(list) 线性时间内，将列表转化为堆
        
        sub = [((arr[i] - x) ** 2, i) for i in range(len(arr))]
        heapq.heapify(sub)
        return sorted([arr[heapq.heappop(sub)[1]] for i in range(k)])        
        '''