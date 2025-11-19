package com.cqupt.leetcode.mainstation.M2154;

import java.util.ArrayList;
import java.util.Comparator;

public class Solution {
    public int findFinalValue(int[] nums, int original) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        list.sort(Comparator.comparingInt(a -> a));
        for (Integer integer : list) {
            if (integer == original) {
                original *= 2;
            }
        }
        return original;
    }
}