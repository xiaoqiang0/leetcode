#!/usr/bin/python

def evalRPN(tokens):
    if tokens == None or len(tokens) == 0:
        return None
    stack = []
    #assume all strings in tokens are integers or operators
    for token in tokens:
        if len(token) == 1 and token[0] in ['+', '-', '*', '/']:
            import ipdb;ipdb.set_trace()
            op2 = stack.pop()
            op1 = stack.pop()
            if token[0] == '+':
                stack.append(int(op1) + int(op2))
            elif token[0] == '-':
                stack.append(int(op1) - int(op2))
            elif token[0] == '*':
                stack.append(int(op1) * int(op2))
            elif token[0] == '/':
                stack.append(int(op1) / float(op2))
        else:
            stack.append(int(token))

    return int(stack.pop())

input1 = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
input2 = ["4","13","5","/","+"]
print evalRPN(input1)
