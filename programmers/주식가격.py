def solution(prices):
    answer = [0 for _ in range(len(prices))]
    stack = []

    for i, p in enumerate(prices):
        if not stack or stack[-1][0] <= p:
            stack.append((p, i))
        else:
            while stack:
                if stack[-1][0] <= p:
                    break

                (pp, j) = stack.pop()
                answer[j] = i - j
            stack.append((p, i))
    while stack:
        (_, j) = stack.pop()
        answer[j] = i - j
    return answer

