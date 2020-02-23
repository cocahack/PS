class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None

        copyMap = {}

        def cloneGraphHelper(original: 'Node', dup: 'Node'):
            copyMap[original] = dup
            dup.val = original.val
            for child in original.neighbors:
                copiedChild = None
                if child in copyMap:
                    copiedChild = copyMap[child]
                else:
                    copiedChild = Node()
                    cloneGraphHelper(child, copiedChild)
                dup.neighbors.append(copiedChild)



        copiedRoot = Node()
        cloneGraphHelper(node, copiedRoot)
        return copiedRoot
