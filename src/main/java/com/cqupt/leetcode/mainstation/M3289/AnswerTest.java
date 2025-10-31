package com.cqupt.leetcode.mainstation.M3289;

import org.junit.Test;

import java.util.Arrays;

public class AnswerTest {
    @Test
    public void test() {
        Solution solution = new Solution();
        int[] nums = {0, 1, 1, 0};
        System.out.println(Arrays.toString(solution.getSneakyNumbers(nums)));
    }
}
