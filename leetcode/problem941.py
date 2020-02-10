class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3 or A[0] >= A[1]:
            return False

        meetSummit = False

        before = A[1]

        for i in range(2, len(A)):
            if before == A[i]:
                return False

            if meetSummit and before < A[i]:
                return False
            elif not meetSummit and before > A[i]:
                meetSummit = True

            before = A[i]


        return meetSummit

