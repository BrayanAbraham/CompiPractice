package leetcode;

import leetcode.utility.ListNode;

public class AddTwoNumbers {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(9,
                new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
        ListNode l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

        ListNode result = new AddTwoNumbers().addTwoNumbers(l1, l2);

        while (result != null) {
            System.out.print(result.val);
            result = result.next;
        }
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = null, head = null , temp = null;
        int carry = 0;

        while (l1 != null && l2 != null) {
            int res = l1.val + l2.val + carry;
            carry = res / 10;
            res %= 10;

            temp = new ListNode(res);
            if (result == null) {
                result = temp;
                head = temp;
            } else {
                head.next = temp;
                head = head.next;
            }

            l1 = l1.next;
            l2 = l2.next;
        }
        
        while (l1 != null) {
            int res = l1.val + carry;
            carry = res / 10;
            res %= 10;

            temp = new ListNode(res);
            if (result == null) {
                result = temp;
                head = temp;
            } else {
                head.next = temp;
                head = head.next;
            }

            l1 = l1.next;
        }

        while (l2 != null) {
            int res = l2.val + carry;
            carry = res / 10;
            res %= 10;

            temp = new ListNode(res);
            if (result == null) {
                result = temp;
                head = temp;
            } else {
                head.next = temp;
                head = head.next;
            }
            l2 = l2.next;
        }

        if (carry > 0) {
            temp = new ListNode(carry);
            if (result == null) {
                result = temp;
                head = temp;
            } else {
                head.next = temp;
                head = head.next;
            }
        }

        return result;
    }
}
