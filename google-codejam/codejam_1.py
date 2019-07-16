def solve(s):
    ret = ''
    for c in s:
        if c == '4':
            ret += '1'
        else:
            ret += '0'
    return int(ret), int(s) - int(ret)

t = int(input())
case = 1
while t > 0:
    n = input()
    a, b = solve(n)
    print("Case #%d: %s %s" % (case, a, b))
    case += 1
    t -= 1
