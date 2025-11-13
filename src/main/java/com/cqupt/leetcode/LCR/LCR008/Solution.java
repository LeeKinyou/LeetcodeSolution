package com.cqupt.leetcode.LCR.LCR008;

public class Solution {
    private int[] prefixSum;

    private boolean ckeck(int[] nums, int len, int target) {
        int maxSum = 0;
        for (int i = len; i < prefixSum.length; i++) {
            maxSum = Math.max(maxSum, prefixSum[i] - prefixSum[i - len]);
        }
        return maxSum >= target;
    }

    public int minSubArrayLen(int target, int[] nums) {
        prefixSum = new int[nums.length + 1];
        prefixSum[0] = 0;
        prefixSum[1] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        if (prefixSum[nums.length] < target) {
            return 0;
        }
        int left = 1, right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (ckeck(nums, mid, target)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}