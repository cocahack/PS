class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:

        def helper(r):
            if r is None:
                return 0
            ret = 0
            if L <= r.val <= R:
                ret += r.val + helper(r.left) + helper(r.right)
            elif r.val < L:
                ret += helper(r.right)
            elif R < r.val:
                ret += helper(r.left)

            return ret


        return helper(root)

