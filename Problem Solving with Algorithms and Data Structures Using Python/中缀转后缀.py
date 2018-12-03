from Stack import Stack
# P47
def InfixToPostfix(infixexpr):
    prec = {}
    prec["*"] = 3
    prec["/"] = 3
    prec["+"] = 2
    prec["-"] = 2
    prec["("] = 1
    opStack = Stack()
    postfixlist = []
    tokenList = infixexpr.split()
    
    for token in tokenList:
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
            postfixlist.append(token)
        elif token == '(':
            opStack.push(token)
        elif token == ')':
            topToken = opStack.pop()
            while topToken != '(':
                postfixlist.append(topToken)
                topToken = opStack.pop()
        else:
            while (not opStack.isEmpty()) and \
            (prec[opStack.peek()] >= prec[token]):
                postfixlist.append(opStack.pop())
            opStack.push(token)
            
    while not opStack.isEmpty():
        postfixlist.append(opStack.pop())        
    return " ".join(postfixlist)
    
print(InfixToPostfix("A * B + C * D"))
print(InfixToPostfix("( A + B ) * C - ( D - E ) * ( F + D )"))