package com.cqupt.leetcode.mainstation.M3318;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.PriorityQueue;

class Solution {
    public int getAns(int[] nums, int l, int r, int x) {
        int ans = 0;
        HashMap<Integer, Integer> integerIntegerHashMap = new HashMap<>();
        for (int i = l; i < r; i++) {
            integerIntegerHashMap.put(nums[i], integerIntegerHashMap.getOrDefault(nums[i], 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(
                (a, b) -> {
                    if (!Objects.equals(a.getValue(), b.getValue())) {
                        return b.getValue() - a.getValue();
                    }
                    return b.getKey() - a.getKey();
                }
        );
        pq.addAll(integerIntegerHashMap.entrySet());
        for (int i = 0; i < x; i++) {
            if (pq.peek() != null) {
                ans += pq.peek().getKey() * pq.peek().getValue();
            }
            pq.poll();
        }
        return ans;
    }

    public int[] findXSum(int[] nums, int k, int x) {
        int[] ans = new int[nums.length - k + 1];
        for (int i = 0; i < nums.length - k + 1; i++) {
            ans[i] = getAns(nums, i, i + k, x);
        }
        return ans;
    }
}