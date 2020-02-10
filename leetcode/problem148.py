# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head == None:
            return None

        cur = head
        N = 0
        while cur != None:
            N += 1
            cur = cur.next

        def splitList(head, N):
            sentinel = ListNode(-1)
            sentinel.next = head
            while head != None and N > 0:
                sentinel = sentinel.next
                N -= 1

            rightHead = sentinel.next
            sentinel.next = None
            return [head, rightHead]


        def mergeSort(head, N):
            if N == 1:
                return head

            mid = N // 2
            head, rightHead = splitList(head, mid)

            head = mergeSort(head, mid)
            rightHead = mergeSort(rightHead, N - mid)

            if head.val <= rightHead.val:
                ret = head
                head = head.next
            else:
                ret = rightHead
                rightHead = rightHead.next

            cur = ret

            while head != None and rightHead != None:
                if head.val <= rightHead.val:
                    cur.next = head
                    head = head.next
                else:
                    cur.next = rightHead
                    rightHead = rightHead.next
                cur = cur.next

            while head != None:
                cur.next = head
                head = head.next
                cur = cur.next

            while rightHead != None:
                cur.next = rightHead
                rightHead = rightHead.next
                cur = cur.next

            return ret

        return mergeSort(head, N)







