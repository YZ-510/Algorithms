# 设计哈希集合
# https://leetcode-cn.com/problems/design-hashset/

class MyHashSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hash = set()

    def add(self, key):
        """
        :type key: int
        :rtype: void
        """
        self.hash.add(key)

    def remove(self, key):
        """
        :type key: int
        :rtype: void
        """
        if key in self.hash:
            self.hash.remove(key)

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        if key in self.hash:
            return True
        else:
            return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
