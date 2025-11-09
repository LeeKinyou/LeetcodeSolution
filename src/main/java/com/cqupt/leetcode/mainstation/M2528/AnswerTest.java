package com.cqupt.leetcode.mainstation.M2528;

import org.junit.Test;

public class AnswerTest {
    @Test
    public void test() {
        Solution solution = new Solution();
        int[] stations = {1,2,4,5,0};
        int r = 1;
        int k = 2;
        long l = solution.maxPower(stations, r, k);
        System.out.println(l);
    }
}
