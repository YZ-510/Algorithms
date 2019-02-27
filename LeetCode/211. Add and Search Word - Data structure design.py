# 添加与搜索单词 - 数据结构设计
# https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/

class TrieNode:
    
    def __init__(self):
        self.childs = dict()
        self.isWord = False


class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: None
        """
        node = self.root
        for letter in word:
            if letter not in node.childs:
                child = TrieNode()
                node.childs[letter] = child
            node = node.childs[letter]
        node.isWord = True

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        def dfs(root, word):
            if len(word) == 0:
                return root.isWord
            elif word[0] == '.':
                for node in root.childs:
                    if dfs(root.childs[node], word[1:]):
                        return True
                return False
            else:
                node = root.childs.get(word[0])
                if node is None:
                    return False
                return dfs(node, word[1:])
            
        return dfs(self.root, word)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)