package com.cqupt.leetcode.mainstation.M1578;

class Solution {
    public int minCost(String colors, int[] neededTime) {
        int ans = 0;
        for (int i = 0; i < colors.length(); i++) {
            char c = colors.charAt(i);
            int sum = 0, maxTime = 0;
            while (i < colors.length() && colors.charAt(i) == c) {
                sum += neededTime[i];
                maxTime = Math.max(maxTime, neededTime[i]);
                i++;
            }
            i--;
//            System.out.println("sum=" + sum + ",maxTime=" + maxTime);
            ans += sum - maxTime;
        }
        return ans;
    }
}