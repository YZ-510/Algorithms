# 实现 Trie（前缀树）
# https://leetcode-cn.com/problems/implement-trie-prefix-tree/

class TrieNode:
    
    def __init__(self):
        self.childs = dict()    # 每个节点中声明一个Hashmap，Hashmap的键是字符，值是相对应的子节点
        self.isWord = False

        
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        node = self.root
        for letter in word:
            child = node.childs.get(letter)
            if child is None:   # if letter not in node.childs
                child = TrieNode()
                node.childs[letter] = child
            node = child
        node.isWord = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        node = self.root
        for letter in word:
            child = node.childs.get(letter)
            if child is None:
                return False
            node = child
        return node.isWord

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        node = self.root
        for letter in prefix:
            child = node.childs.get(letter)
            if child is None:
                return False
            node = child
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)