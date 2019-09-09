# push 的时候直接 push 进 stack1
# pop 时，若 stack2 不为空，直接 pop；若 stack2 为空，需将 stack1 中的值全部放入 stack2 中，再 pop

class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    
    def push(self, node):
        # write code here
        self.stack1.append(node)
    
    def pop(self):
        # return xx
        if len(stack1) == 0 and len(stack2) == 0:
            return
        elif len(stack2) == 0:
            while len(stack1) > 0:
                self.stack2.append(self.stack1.pop())
        
        return self.stack2.pop()