package com.cqupt.leetcode.mainstation.M1437;

class Solution {
    private boolean isValid(int[] nums, int k) {
        int pos = -Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                if (i - pos - 1 < k)
                    return false;
                pos = i;
            }
        }
        return true;
     }
    public boolean kLengthApart(int[] nums, int k) {
        return isValid(nums, k);
    }
}