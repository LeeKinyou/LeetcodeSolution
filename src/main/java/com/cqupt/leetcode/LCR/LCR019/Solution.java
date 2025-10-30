package com.cqupt.leetcode.LCR.LCR019;

public class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        return s.contentEquals(sb);
    }

    public boolean validPalindrome(String s) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        if (s.contentEquals(sb)) {
            return true;
        }
        for (int i = 0; i < s.length(); i++) {
            StringBuilder ssb = new StringBuilder();
            ssb.append(s, 0, i);
            ssb.append(s.substring(i + 1));
            if (isPalindrome(ssb.toString())) {
                return true;
            }
        }
        return false;
    }
}