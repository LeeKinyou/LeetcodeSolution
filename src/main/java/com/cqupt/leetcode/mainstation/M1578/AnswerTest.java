package com.cqupt.leetcode.mainstation.M1578;

import org.junit.Test;

public class AnswerTest {
    @Test
    public void test() {
         String colors = "cddcdcae";
         int[] neededTime = {4,8,8,4,4,5,4,2};
         System.out.println(new Solution().minCost(colors, neededTime));
    }
}
