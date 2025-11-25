package com.cqupt.leetcode.mainstation.M1018;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    private Boolean getNum(int[] nums, int index) {
        int cnt = 0;
        for (int i = 0; i <= index; i++) {
            cnt = (cnt * 2 + nums[i]) % 5;
        }
        return cnt == 0;
    }

    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (getNum(nums, i)) {
                   list.add(true);
            } else {
                list.add(false);
            }
        }
        return list;
    }
}