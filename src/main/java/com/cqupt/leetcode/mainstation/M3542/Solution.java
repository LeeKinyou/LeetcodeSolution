package com.cqupt.leetcode.mainstation.M3542;

public class Solution {
    private int[] segmentTree;
    private int[] nums;
    private int n;

    private void buildSegmentTree(int[] array) {
        this.nums = array;
        this.n = array.length;
        this.segmentTree = new int[4 * n];
        buildTree(0, 0, n - 1);
    }

    private void buildTree(int node, int start, int end) {
        if (start == end) {
            segmentTree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(2 * node + 1, start, mid);
            buildTree(2 * node + 2, mid + 1, end);
            segmentTree[node] = Math.min(segmentTree[2 * node + 1], segmentTree[2 * node + 2]);
        }
    }

    private int queryRangeMin(int node, int start, int end, int left, int right) {
        if (right < start || left > end) {
            return Integer.MAX_VALUE;
        }
        if (left <= start && end <= right) {
            return segmentTree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = queryRangeMin(2 * node + 1, start, mid, left, right);
        int rightMin = queryRangeMin(2 * node + 2, mid + 1, end, left, right);
        return Math.min(leftMin, rightMin);
    }

    private int rangeMinQuery(int left, int right) {
        return queryRangeMin(0, 0, n - 1, left, right);
    }

    private int work(int[] nums, int l, int r) {
        int minNum = rangeMinQuery(l, r - 1);
        int cnt = minNum == 0 ? 0 : 1;
        int lef = l, rig = -1;
        if (l == r - 1) {
            return minNum == 0 ? 0 : 1;
        }
        for (int i = l; i < r; i++) {
            if (nums[i] == minNum) {
                rig = i;
                if (lef != rig) {
                    cnt += work(nums, lef, rig);
                }
                lef = i + 1;
            }
            if (i == r - 1 && lef != r) {
                cnt += work(nums, lef, r);
            }
        }
        return cnt;
    }

    public int minOperations(int[] nums) {
        buildSegmentTree(nums);
        return work(nums, 0, nums.length);
    }
}