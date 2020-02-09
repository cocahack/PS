class Solution:
    def decodeString(self, s: str) -> str:
        if len(s) == 0:
            return ""

        stack = [s[0]]

        it = 1
        while it < len(s):
            c = s[it]
            if c.isalpha():
                if stack[-1].isalpha():
                    stack[-1] += c
                else:
                    stack.append(c)
            elif c.isnumeric():
                if stack[-1].isnumeric():
                    stack[-1] += c
                else:
                    stack.append(c)
            elif c == ']':
                substr = stack.pop(-1)
                stack.pop(-1)
                multiple = int(stack.pop(-1))
                acc = multiple * substr
                while len(stack) > 0 and stack[-1].isalpha():
                    acc = stack.pop(-1) + acc
                stack.append(acc)
            else:
                stack.append(c)
            it += 1


        return stack[0]

