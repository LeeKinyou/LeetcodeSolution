package com.cqupt.leetcode.mainstation.M2257;

import java.util.ArrayDeque;
import java.util.Queue;

public class Solution {

    private static final int[][] DIRS = {{1,0},{-1,0},{0,1},{0,-1}};
    private static final int GUARD = -1;
    private static final int WALL = -2;

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];
        Queue<int[]> queue = new ArrayDeque<>();
        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
            for (int i = 0; i < 4; i++) {
                queue.offer(new int[]{guard[0], guard[1], i});
            }
        }
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }
        while (!queue.isEmpty()) {
            int[] poll = queue.poll();
            int nx = poll[0] + DIRS[poll[2]][0], ny = poll[1] + DIRS[poll[2]][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] >= 0 && (grid[nx][ny] & (1 << poll[2])) == 0) {
                grid[nx][ny] |= (1 << poll[2]);
                queue.offer(new int[]{nx, ny, poll[2]});
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
}