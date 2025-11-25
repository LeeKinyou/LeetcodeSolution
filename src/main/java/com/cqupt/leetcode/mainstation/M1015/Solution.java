package com.cqupt.leetcode.mainstation.M1015;

import java.util.HashSet;

public class Solution {
    public int smallestRepunitDivByK(int k) {
        HashSet<Integer> set = new HashSet<>();
        int remainder = 1 % k, count = 1;
        while (remainder != 0) {
            remainder = (remainder * 10 + 1) % k;
            if (set.contains(remainder)) {
                return -1;
            }
            set.add(remainder);
            count++;
        }
        return count;
    }
}