package com.cqupt.leetcode.mainstation.M3228;

public class Solution {
    public int maxOperations(String s) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '1' && s.charAt(i + 1) == '0') {
                ans++;
                ans += cnt;
                cnt++;
            } else if (s.charAt(i) == '1') {
                cnt++;
            }
        }
        return ans;
    }
}