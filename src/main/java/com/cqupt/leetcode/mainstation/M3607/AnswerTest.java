package com.cqupt.leetcode.mainstation.M3607;

import org.junit.Test;

import java.util.Arrays;

public class AnswerTest {
    @Test
    public void test() {
        Solution solution = new Solution();
        int[][] connections = {{1,2}};
        int[][] queries = {{2,1},{1,2},{2,1},{1,1},{1,2},{1,1},{1,1},{2,1},{2,2}};
        int c = 2;
        int[] ints = solution.processQueries(c, connections, queries);
        System.out.println(Arrays.toString(ints));
    }
}
