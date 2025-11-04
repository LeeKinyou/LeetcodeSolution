package com.cqupt.leetcode.mainstation.M3318;

import org.junit.Test;

import java.util.Arrays;

public class AnswerTest {
    @Test
    public void test() {
        Solution solution = new Solution();
        int[] nums = {9,2,2};
        int k = 3;
        int x = 3;
        int[] ans = solution.findXSum(nums, k, x);
        System.out.println(Arrays.toString(ans));
    }
}
