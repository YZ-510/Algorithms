from Deque import Deque

def palcheck(aString):
    chardeque = Deque()
    
    for ch in aString:
        chardeque.addRear(ch)
        
    stillEqual = True
    
    while chardeque.size() > 1 and stillEqual:
        first = chardeque.removeFront()
        last = chardeque.removeRear()
        if first != last:
            stillEqual = False
        
    return stillEqual

print(palcheck("lsdkjfskf"))
print(palcheck("radar"))