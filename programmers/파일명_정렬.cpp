def solution(files):
    answer = []
    fs = []

    for idx, f in enumerate(files):
        i = 0
        for c in f:
            if c.isdigit():
                break
            i += 1
        head = f[:i].lower()
        start = i

        while i < len(f):
            if not f[i].isdigit():
                break
            i += 1

        fs.append([head, int(f[start:i]), idx])

    fs.sort()

    for f in fs:
        answer.append(files[f[2]])

    return answer

