/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null) {
            return null;
        }
        ListNode sentinel = new ListNode(-1);
        sentinel.next = new ListNode(head.val);
        head = head.next;
        while(head != null) {
            ListNode prev = sentinel.next;
            sentinel.next = new ListNode(head.val);
            sentinel.next.next = prev;
            head = head.next;
        }
        
        return sentinel.next;
    }
}

