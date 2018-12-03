def BinaryTree(r):
    return [r, [], []]
    
def insertLeft(root, newBranch):
    t = root.pop(1)
    if len(t) > 1:
        root.insert(1, [newBranch, t, []])
    else:
        root.insert(1, [newBranch, [], []])
    return root
    
def insertRight(root, newBranch):
    t = root.pop(2)
    if len(t) > 1:
        root.insert(2, [newBranch, [], t])
    else:
        root.insert(2, [newBranch, [], []])
    return root

def gerRootVal(root):
    return root[0]
    
def setRootVal(root, newVal):
    root[0] = newVal
    
def getRightChild(root):
    return root[2]
    
myTree = BinaryTree(1)
insertLeft(myTree, 2)
insertRight(myTree, 3)
print(myTree)
insertLeft(myTree, 4)
insertRight(myTree, 5)
print(myTree)
print(myTree[1])
print(myTree[0])
print(myTree[2])