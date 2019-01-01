# 常数时间插入、删除和获取随机元素
# https://leetcode-cn.com/problems/insert-delete-getrandom-o1/

class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 使用字典和列表，字典的 key 和 value 分别为元素和其 index
        
        self.dic = {}
        self.lst = []

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.dic:
            self.lst.append(val)
            self.dic[val] = len(self.lst) - 1
            return True
        return False

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.dic:
            idx = self.dic[val]
            self.lst[idx] = self.lst[-1]    # 末尾元素替换到删除元素的 index 位置
            self.dic[self.lst[idx]] = idx
            self.lst.pop()                  # 删除末尾元素
            del self.dic[val]
            return True
        return False
        
    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        idx = random.randint(0, len(self.lst) -1)
        return self.lst[idx]
        
        # return random.choice(self.lst)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()