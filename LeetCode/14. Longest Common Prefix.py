# 最长公共前缀
# https://leetcode-cn.com/problems/longest-common-prefix/

class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """       
#        return os.path.commonprefix(strs)
        '''
        最长公共前缀 LCP 存在的话一定也在第一字符串 strs[0] 中，且长度不会大于第一个字符串的长度
        依次假设 LCP 长度为 0到len(strs[0])，strs[0][:i]
        每一轮遍历中，只要 strs 中存在比当前 LCP 长度 i 更短的 str，返回上一轮的 LCP;
        只要 strs 中 str 索引 i 的字符与 LCP 的不一样，返回上一轮的 LCP
        若一直没返回，说明 strs[0] 本身就是 LCP
        '''
        
        if not strs:
            return ""
        for i in range(len(strs[0])):
            for str in strs:
                if len(str) <= i or strs[0][i] != str[i]:
                    return strs[0][:i]
                
        return strs[0]