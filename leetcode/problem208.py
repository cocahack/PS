class TrieNode:

    def __init__(self):
        self.is_end = False
        self.next = {}


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = TrieNode()


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        localHead = self.head
        def dfs(head, word, idx):
            if idx == len(word):
                head.is_end = True
                return

            if word[idx] not in head.next:
                head.next[word[idx]] = TrieNode()

            dfs(head.next[word[idx]], word, idx+1)

        dfs(localHead, word, 0)


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        localHead = self.head
        def dfs(head: TrieNode, word, idx):
            if idx == len(word):
                return head.is_end

            if word[idx] not in head.next:
                return False

            return dfs(head.next[word[idx]], word, idx+1)

        return dfs(localHead, word, 0)




    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        localHead = self.head
        def dfs(head: TrieNode, word, idx):
            if idx == len(word):
                return True

            if word[idx] not in head.next:
                return False

            return dfs(head.next[word[idx]], word, idx+1)

        return dfs(localHead, prefix, 0)

