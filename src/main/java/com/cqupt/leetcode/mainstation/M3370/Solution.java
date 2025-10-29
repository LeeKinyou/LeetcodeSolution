package com.cqupt.leetcode.mainstation.M3370;


import java.util.ArrayList;

public class Solution {
    public ArrayList<Integer> getBinaryList(int n) {
        ArrayList<Integer> integers = new ArrayList<>();
        while (n != 0) {
            integers.add(n % 2);
            n /= 2;
        }
        // 将二进制数组正序返回
//        for (int i = 0; i < integers.size() / 2; i++) {
//            int temp = integers.get(i);
//            integers.set(i, integers.get(integers.size() - i - 1));
//            integers.set(integers.size() - i - 1, temp);
//        }
        return integers;
    }

    public int getNumber(ArrayList<Integer> list) {
        int res = 0;
        for (int i = 0; i < list.size(); i++) {
            res += (int) (list.get(i) * Math.pow(2, i));
        }
        return res;
    }

    public int smallestNumber(int n) {
        ArrayList<Integer> res = getBinaryList(n);
//        System.out.println(res);
        for (int i = 0; i < res.size(); i++) {
            if (res.get(i) == 0) {
                res.set(i, 1);
            }
        }
        return getNumber(res);
    }
}