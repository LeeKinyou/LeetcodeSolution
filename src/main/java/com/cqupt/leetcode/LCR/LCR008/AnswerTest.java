package com.cqupt.leetcode.LCR.LCR008;

import org.junit.Test;

public class AnswerTest {
    @Test
    public void test() {
        Solution solution = new Solution();
        int i = solution.minSubArrayLen(11, new int[]{1, 1, 1, 1, 1, 1, 1, 1});
        System.out.println(i);
    }
}
