package com.cqupt.leetcode.mainstation.M717;

public class Solution {
    private boolean flag = false;

    private void dfs(int[] bits, int index) {
        if (index >= bits.length) {
            return;
        }
        if (index == bits.length - 1) {
            if (bits[index] == 0) {
                flag = true;
                return;
            }
        }
        if (bits[index] == 1) {
            dfs(bits, index + 2);
        } else {
            dfs(bits, index + 1);
        }
    }

    public boolean isOneBitCharacter(int[] bits) {
        dfs(bits, 0);
        return flag;
    }
}