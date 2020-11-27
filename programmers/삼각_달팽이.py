def solution(n):
    delta = [[1, 0], [0, 1], [-1, -1]]
    turn = 0
    max_move = n
    num = 1
    curr = [-1, 0]
    answer = []
    _2d_answer = []

    for i in range(n):
        _2d_answer.append([0 for _ in range(i + 1)])

    while max_move > 0:
        moved = 0
        while moved < max_move:
            curr[0] = curr[0] + delta[turn][0]
            curr[1] = curr[1] + delta[turn][1]
            _2d_answer[curr[0]][curr[1]] = num
            num = num + 1
            moved = moved + 1
        turn = (turn + 1) % 3
        max_move = max_move - 1

    for i in range(n):
        for j in range(i+1):
            answer.append(_2d_answer[i][j])

    return answer

