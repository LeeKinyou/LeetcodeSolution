package com.cqupt.leetcode.mainstation.M3289;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        for (var entry : map.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            if (value == 2) {
                list.add(key);
            }
        }
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}