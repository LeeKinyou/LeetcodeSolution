package com.cqupt.leetcode.mainstation.M3217;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        for (var s : set) {
            System.out.println(s);
        }
        while (head != null) {
            if (set.contains(head.val)) {
                head = head.next;
            } else {
                break;
            }
        }
        if (head != null) {
            System.out.println("head: " + head.val);
        }
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            if (set.contains(cur.next.val)) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }
        return head;
    }
}