class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode sentinel = new ListNode(-1);
        ListNode sentinelPtr = sentinel;
        
        int count = 0;
        
        while(count++ < m - 1) {
            sentinelPtr.next = new ListNode(head.val);
            sentinelPtr = sentinelPtr.next;
            head = head.next;
        }
        
        sentinelPtr.next = reverseBetweenHelper(head, n - m + 1);
        
        count = 0;
        while(count++ <= n - m) {
            head = head.next;
            sentinelPtr = sentinelPtr.next;
        }
        
        sentinelPtr.next = head;
        
        return sentinel.next;
    }
    
    private ListNode reverseBetweenHelper(ListNode head, int count) {
        ListNode sentinel = new ListNode(-1);
        
        while(count-- != 0) {
            ListNode newNode = new ListNode(head.val);
            newNode.next = sentinel.next;
            sentinel.next = newNode;
            head = head.next;
        }
        
        return sentinel.next;
    }
}

