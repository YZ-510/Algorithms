# 字母异位词分组
# https://leetcode-cn.com/problems/group-anagrams/

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        if len(strs) == 0 or len(strs) == 1:
            return [strs]
        
        dic = {}
        res = []
        
        # 遍历字符串
        # 对字符进行排序并使用排序后的字符作为键
        
        for s in strs:
            s_ = ''.join(sorted(s))
            if s_ not in dic:
                dic[s_] = [s]
            else:
                dic[s_].append(s)
        
        for key in dic:
            res.append(dic[key])
            
        return res
