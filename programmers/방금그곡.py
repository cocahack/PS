def solution(m, musicinfos):
    answer = '(None)'
    longest = 0

    m = tf(m)

    for info in musicinfos:
        start, end, title, notes = info.split(',')
        r = getDiff(start, end)
        if r <= longest:
            continue
        notes = tf(notes)
        N = len(notes)
        if N < r:
            diff = r - N
            it = diff // N
            remains = diff % N
            notes += notes * it + notes[:remains]
        if r < N:
            notes = notes[:r]

        try:
            notes.index(m)
            answer = title
            longest = r
        except:
            pass

    return answer

def getDiff(start, end):
    return getTime(end) - getTime(start)

def getTime(t):
    h, s = t.split(':')
    return int(h) * 60 + int(s)

noteDict = {
    'C': 'a',
    'C#': 'b',
    'D': 'c',
    'D#': 'd',
    'E': 'e',
    'E#': 'm',
    'F': 'f',
    'F#': 'g',
    'G': 'h',
    'G#': 'i',
    'A': 'j',
    'A#': 'k',
    'B': 'l',
    'B#': 'z'
}

def tf(notes):
    idx = 0
    ret = []
    N = len(notes)
    while idx < N:
        if idx + 1 < N and notes[idx+1] == '#':
            ret.append(noteDict[notes[idx:idx+2]])
            idx += 2
        else:
            ret.append(noteDict[notes[idx]])
            idx += 1
    return ''.join(ret)


