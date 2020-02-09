# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def splitBST(self, root: TreeNode, V: int) -> List[TreeNode]:
        if(root == None):
            return [None, None]

        if root.val == V:
            right = root.right
            root.right = None
            return [root, right]
        else:
            if V < root.val:
                splittedTree = self.splitBST(root.left, V)
                root.left = splittedTree[1]
                return [splittedTree[0], root]
            else:
                splittedTree = self.splitBST(root.right, V)
                root.right = splittedTree[0]
                return [root, splittedTree[1]]
