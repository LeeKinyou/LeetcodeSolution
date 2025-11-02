package com.cqupt.leetcode.mainstation.M2257;

import org.junit.Test;

public class AnswerTest {
    @Test
    public void answerTest() {
        int[][] guards = new int[][]{{0, 0}, {4, 4}};
        int[][] walls = new int[][]{{3, 2}, {3, 4}};
        System.out.println(new Solution().countUnguarded(5, 5, guards, walls));
    }
}
