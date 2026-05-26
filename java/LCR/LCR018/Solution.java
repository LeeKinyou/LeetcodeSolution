package com.cqupt.leetcode.LCR.LCR018;

public class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                sb.append(Character.toLowerCase(c));
            }
        }
        StringBuilder ssb = new StringBuilder(sb);
        sb.reverse();
        return sb.toString().contentEquals(ssb);
    }
}