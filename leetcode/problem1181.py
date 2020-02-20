class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        answer = set()

        for i, before in enumerate(phrases):
            for j, after in enumerate(phrases):
                if i == j:
                    continue

                splittedBefore = before.split(' ')
                splittedAfter = after.split(' ')
                splittedAfter.append(' ')
                if splittedBefore[-1] == splittedAfter[0]:
                    splittedBefore += splittedAfter[1:]
                    answer.add(' '.join(splittedBefore).strip())

        return sorted(list(answer))

