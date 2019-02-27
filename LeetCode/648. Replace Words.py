# 单词替换
# https://leetcode-cn.com/problems/replace-words/

class TrieNode:
    
    def __init__(self):
        self.childs = dict()
        self.isWord = False

        
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for letter in word:
            child = node.childs.get(letter)
            if child is None:
                child = TrieNode()
                node.childs[letter] = child
            node = child
        node.isWord = True
        
    def find_prefix(self, word):
        node = self.root
        prefix = ''
        for letter in word:     # 遍历单词中字符
            prefix += letter
            child = node.childs.get(letter)
            if child is None:
                return word
            else:
                if node.childs[letter].isWord:
                    return prefix
                else:
                    node = child
        return word


class Solution(object):
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        '''
        词典中的词根 root 放入前缀树中，遍历句子中的单词，查找其前缀
        '''
        trie = Trie()
        for root in dict:
            trie.insert(root)
        
        res = []
        for word in sentence.split():
            res.append(trie.find_prefix(word))
        return ' '.join(res)


'''
        strs = sentence.split()
        for i in range(len(strs)):
            for j in dict:
                if strs[i].startswith(j):
                    strs[i] = j
        
        return ' '.join(strs)

'''     
'''        
        rootset = set(dict)
        
        def replace(word):
            for i in range(1, len(word)):
                if word[:i] in rootset:
                    return word[:i]
            return word
        
        return ' '.join(map(replace, sentence.split()))
'''