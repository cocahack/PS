from typing import *
import unittest


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        event = []
        for it, interval in enumerate(intervals):
            event.append([interval[0], 0, it])
            event.append([interval[1], 1, it])
        event.sort()

        stack = []
        answer = []

        for e in event:
            if e[1] == 0:
                stack.append(e)
            else:
                if len(stack) == 1:
                    answer.append([stack[0][0], e[0]])
                stack.pop(-1)


        return answer


s = Solution()
print(s.merge([[1,3],[2,6],[8,10],[15,18]]))

