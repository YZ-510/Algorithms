# 两个列表的最小索引总和
# https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/

class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        dic = {}
        res = []
        index = float("inf")
        
        for i in range(len(list1)):
            dic[list1[i]] = i
            
        for j in range(len(list2)):
            if list2[j] in dic:
                if index > j + dic[list2[j]]:
                    if res == []:
                        res.append(list2[j])
                    else:
                        res.pop(-1)
                        res.append(list2[j])
                elif index == j + dic[list2[j]]:
                    res.append(list2[j])
                index = j + dic[list2[j]]
                
        return res
