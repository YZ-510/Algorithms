# 键值映射
# https://leetcode-cn.com/problems/map-sum-pairs/

class TrieNode:
    
    def __init__(self):
        self.childs = dict()
        self.value = 0


class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        self.keys = dict()  # 存储已经 insert 过的键值对

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: None
        """
        node = self.root
        delta = val - self.keys.get(key, 0) # 若 key 不存在，返回 0        
#        if self.keys.get(key):
#            delta = val - self.keys[key]   若 key 已经 insert 过，计算两个值的差值，调整其子节点
#        else:
#            delta = val
        self.keys[key] = val
        for letter in key:
            child = node.childs.get(letter)
            if child is None:
                child = TrieNode()
                node.childs[letter] = child
            node = child
            node.value += delta

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        node = self.root
        for letter in prefix:
            child = node.childs.get(letter)
            if child is None:
                return 0
            node = child
#        print(self.keys)
        return node.value

'''

class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = dict()

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: None
        """
        self.dic[key] = val

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        res = 0
        for k, v in self.dic.items():
            if k.startswith(prefix):
                res += v
        return res

'''

# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)