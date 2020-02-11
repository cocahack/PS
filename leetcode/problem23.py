from queue import PriorityQueue


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists) == 0:
            return None

        q = PriorityQueue()
        count = 1

        sentinel = ListNode(-1)

        for head in lists:
            while head != None:
                q.put(head.val)
                head = head.next

        head = sentinel
        while not q.empty():
            node = ListNode(q.get())
            head.next = node
            head = head.next

        return sentinel.next
