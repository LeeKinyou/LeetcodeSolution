package com.cqupt.leetcode.mainstation.M3607;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;

public class ArrayListTest {
    int[] nums = new int[6];

    ArrayList<Integer> numsList = new ArrayList<>();
    private int findNums(int x) {
        if (x == nums[x])
            return x;
        return nums[x] = findNums(nums[x]);
    }

    private void unionNums(int x, int y) {
        int fx = findNums(x);
        int fy = findNums(y);
        if (fx != fy) {
            nums[fx] = fy;
        }
    }

    private int findNumsList(int x) {
        if (x == numsList.get(x))
            return x;
        return numsList.set(x, findNumsList(numsList.get(x)));
    }

    private void unionNumsList(int x, int y) {
        int fx = findNumsList(x);
        int fy = findNumsList(y);
        if (fx != fy) {
            numsList.set(fx, fy);
        }
    }

    @Test
    public void test() {
        for (int i = 0; i <= 5; i++) {
            nums[i] = i;
        }
        for (int i = 0; i <= 5; i++) {
            numsList.add(i);
        }
        for (int i = 1; i < 5; i++) {
            unionNums(i, i + 1);
            unionNumsList(i, i + 1);
        }
        System.out.println(Arrays.toString(nums));
        System.out.println(numsList);
    }
}
