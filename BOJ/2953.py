highest = -1
winner = 0
for i in range(0, 5):
    score = sum(map(int, input().split()))
    if score > highest:
        highest = score
        winner = i
print(winner+1, highest)
