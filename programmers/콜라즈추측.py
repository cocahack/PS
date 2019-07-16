def solution(num):
    for i in range(0, 501):
        if num == 1:
            return i
        if num % 2 == 1:
            num = num * 3 + 1
        else:
            num = num / 2
        
    return -1
