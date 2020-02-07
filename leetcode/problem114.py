from typing import *
import unittest

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def flatten_left(self, root, right):
        if root.right != None:
            self.flatten_left(root.right, right)
        else:
            root.right = right
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root == None:
            return
        self.flatten(root.left)
        self.flatten(root.right)
        if root.left != None:
            self.flatten_left(root.left, root.right)
            root.right = root.left
            root.left = None
