package com.cqupt.leetcode.mainstation.M1526;

class Solution {
    public int minNumberOperations(int[] target) {
        int ans = 0;
        for (int i = 0; i < target.length; i++) {
            if (i == 0) {
                ans += target[i];
            } else {
                if (target[i] > target[i - 1]) {
                    ans += target[i] - target[i - 1];
                }
            }
        }
        return ans;
    }
}