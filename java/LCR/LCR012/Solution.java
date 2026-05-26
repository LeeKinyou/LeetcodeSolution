package com.cqupt.leetcode.LCR.LCR012;

public class Solution {
    public int getNum(int[] nums, int left, int right) {
        if (right == -1 || left == nums.length) {
            return 0;
        }
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }
        return sum;
    }
    public int pivotIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int left = getNum(nums, 0, i - 1);
            int right = getNum(nums, i + 1, nums.length - 1);
            // System.out.println(left + " " + right);
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
}