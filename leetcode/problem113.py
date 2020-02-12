# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        answer = []

        def dfs(root, accumulate, path):
            if root == None:
                return
            if root.left == None and root.right == None:
                if accumulate + root.val == sum:
                    path.append(root.val)
                    answer.append(path[:])
                    path.pop(-1)
                return

            path.append(root.val)
            dfs(root.left, accumulate + root.val, path)
            dfs(root.right, accumulate + root.val, path)
            path.pop(-1)

        dfs(root, 0, [])
        return answer

