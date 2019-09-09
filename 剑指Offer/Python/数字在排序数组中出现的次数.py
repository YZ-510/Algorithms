
class Solution:
    def GetNumberOfK(self, data, k):
        # write code here
        if data == []:
            return 0
        
        count = 0
        for i in range(len(data)):
            if data[i] == k:
                count += 1
            elif data[i] > k:
                break
        
        return count

# 二分查找
# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, data, k):
        # write code here
        if data == []:
            return 0
        
        firstk = self.GetFirstK(data, k)
        lastk = self.GetLastK(data, k)
        
        if firstk == -1 or lastk == -1:
            return 0
        return lastk - firstk + 1
    
    def GetFirstK(self, data, k):
        low = 0
        high = len(data) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if data[mid] == k:
                if mid == low or data[mid - 1] != k:
                    return mid
                else:
                    high = mid - 1
            elif data[mid] > k:
                high = mid - 1
            else:
                low = mid + 1
        return -1
    
    def GetLastK(self, data, k):
        low = 0
        high = len(data) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if data[mid] == k:
                if mid == high or data[mid + 1] != k:
                    return mid
                else:
                    low = mid + 1
            elif data[mid] > k:
                high = mid - 1
            else:
                low = mid + 1
        return -1