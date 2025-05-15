class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            
            if c in [')', ']', '}'] and len(stack) == 0:
                return False
            if c == ')' and stack.pop() != '(' :
                return False
            if c == ']' and stack.pop() != '[':
                return False
            if c == '}' and stack.pop() != '{':
                return False
            if c in ['(', '[', '{']:
                stack.append(c)
            
        return len(stack) == 0