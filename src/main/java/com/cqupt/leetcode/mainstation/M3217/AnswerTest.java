package com.cqupt.leetcode.mainstation.M3217;

import org.junit.Test;

public class AnswerTest {
    @Test
    public void answerTest() {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        ListNode listNode = new Solution().modifiedList(new int[]{1, 2, 3}, head);
        while (listNode != null) {
            System.out.println(listNode.val);
            listNode = listNode.next;
        }
    }
}
