def solution(weight):
    answer = 0
    N = len(weight)
    weight.sort()

    for i in range(N):
        if answer + 1 < weight[i]:
            break
        answer += weight[i]
    return answer + 1
