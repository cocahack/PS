def solution(name):
    answer = 0
    moveUpDown = []

    for i in range(0, len(name)):
        diff = min(ord(name[i]) - ord('A'), (ord('A') - ord(name[i])) % 26, key=abs)
        answer += diff
        moveUpDown.append(diff)

    visited = list(map(lambda e : False if e else True, moveUpDown))
    cur = 0
    while not all(visited):
        rmove = 0
        lmove = 0
        while visited[cur+rmove]:
            rmove += 1
        while visited[cur+lmove]:
            lmove -= 1

        if rmove <= abs(lmove):
            cur += rmove
            answer += rmove
        else:
            answer += abs(lmove)
            cur += lmove

        visited[cur] = True;

    return answer
