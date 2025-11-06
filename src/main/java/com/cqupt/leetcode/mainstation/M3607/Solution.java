package com.cqupt.leetcode.mainstation.M3607;

import java.util.*;

class Solution {
    private int[] father;
    private final Set<Integer> isOffline = new HashSet<>();
    private final Map<Integer, PriorityQueue<Integer>> group = new HashMap<>();
    private final Map<Integer, Integer> groupId = new HashMap<>();

    private int find(int x) {
        if (x == father[x])
            return x;
        return father[x] = find(father[x]);
    }

    private void union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
        }
    }

    public int getAns(int opt, int id) {
        if (opt == 1) {
            if (!isOffline.contains(id)) {
                return id;
            } else {
                PriorityQueue<Integer> integers = group.get(groupId.get(father[id]));
                while (!integers.isEmpty()) {
                    int peek = integers.peek();
                    if (!isOffline.contains(peek)) {
                        return peek;
                    }
                    integers.poll();
                }
                return -1;
            }
        }
        else {
            isOffline.add(id);
            return 0;
        }
    }

    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        father = new int[c + 1];
        for (int i = 0; i <= c; i++) {
            father[i] = i;
        }
        for (int[] connection : connections) {
            int idA = connection[0];
            int idB = connection[1];
            if (find(idA) != find(idB)) {
                union(idA, idB);
            }
        }
        System.out.println(Arrays.toString(father));

        int groupCnt = 0;
        for (int i = 1; i <= c; i++) {
            int fa = find(i);
            if (!groupId.containsKey(fa)) {
                groupCnt++;
                groupId.put(fa, groupCnt);
                group.put(groupCnt, new PriorityQueue<>());
            }
            int thisGroupId = groupId.get(fa);
            group.get(thisGroupId).add(i);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int[] query : queries) {
            int opt = query[0];
            int id = query[1];
            if (opt == 1) {
                ans.add(getAns(opt, id));
            } else {
                getAns(opt, id);
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}