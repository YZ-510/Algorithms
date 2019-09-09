# 数组中可能存在重复数字，如果首元素小于尾元素，说明该数组是排序的
# 如果中间点大于首元素，说明最小数字在中间点后面；如果中间点小于尾元素，说明最小数字在中间点前面

class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if rotateArray == []:
            return 0
        front, rear = 0, len(rotateArray) - 1
        minVal = rotateArray[0]
        if rotateArray[front] < rotateArray[rear]:
            return rotateArray[front]
        while (rear - front) > 1:
            mid = (front + rear) // 2
            if rotateArray[mid] >= rotateArray[front]:
                front = mid
            elif rotateArray[mid] <= rotateArray[rear]:
                rear = mid
            elif rotateArray[front] == rotateArray[rear] == rotateArray[mid]:
                for i in range(1, len(rotateArray) - 1):
                    if rotateArray[i] < minVal:
                        minval = rotateArray[i]
                        rear = i
        minVal = rotateArray[rear]
        
        return minVal