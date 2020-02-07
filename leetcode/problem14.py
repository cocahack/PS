from typing import *
import unittest


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ''
        for s in strs:
            if len(prefix) < len(s):
                prefix = s

        for s in strs:
            if len(prefix) == 0:
                break
            while len(prefix) > len(s):
                prefix = prefix[:-1]
            for i, c in enumerate(s):
                if len(prefix) == i:
                    break
                if c != prefix[i]:
                    prefix = prefix[:i]
                    break

        return prefix

s = Solution()
print(s.longestCommonPrefix(["flower","flow","flight"]))
print(s.longestCommonPrefix(["dog","racecar","car"]))
print(s.longestCommonPrefix(["aaa","aa","aaa"]))

