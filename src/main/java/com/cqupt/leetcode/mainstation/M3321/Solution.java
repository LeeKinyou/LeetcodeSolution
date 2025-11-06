package com.cqupt.leetcode.mainstation.M3321;

import java.util.*;

class Solution {
    private final HashMap<Integer, Integer> integerHashMap = new HashMap<>();

    private final HashMap<Integer, Integer> integerIsChangeHashMap = new HashMap<>();

    private final PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(
        (a, b) -> {
            if (!Objects.equals(a.getValue(), b.getValue())) {
                return b.getValue() - a.getValue();
            }
            return b.getKey() - a.getKey();
        }
    );

    public int firstXSum(int[] nums, int l, int r, int x) {
        int ans = 0;
        for (int i = l; i < r; i++) {
            integerHashMap.put(nums[i], integerHashMap.getOrDefault(nums[i], 0) + 1);
        }
        pq.addAll(integerHashMap.entrySet());
        for (int i = 0; i < x; i++) {
            if (pq.peek() != null) {
                ans += pq.peek().getKey() * pq.peek().getValue();
            }
            pq.poll();
        }
        return ans;
    }

    private int getAnsSingle(int[] nums, int oldNumber, int newNumber, int x) {
        int ans = 0;
        integerHashMap.put(oldNumber, integerHashMap.getOrDefault(oldNumber, 0) - 1);
        integerHashMap.put(newNumber, integerHashMap.getOrDefault(newNumber, 0) + 1);
        integerIsChangeHashMap.put(newNumber, integerIsChangeHashMap.getOrDefault(newNumber, 0) + 1);
        integerIsChangeHashMap.put(oldNumber, integerIsChangeHashMap.getOrDefault(newNumber, 0) - 1);
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
        ans[0] = firstXSum(nums, 0, k, x);
        for (int i = k; i < nums.length - k + 1; i++) {
            ans[i] = getAnsSingle(nums, nums[i - k], nums[i], x);
        }
        return ans;
    }
}

class Helper {
    private int x;
    private long result;
    private TreeSet<Pair> large, small;
    private Map<Integer, Integer> occ;

    private static class Pair implements Comparable<Pair> {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.first != other.first) {
                return Integer.compare(this.first, other.first);
            }
            return Integer.compare(this.second, other.second);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Pair pair = (Pair) obj;
            return first == pair.first && second == pair.second;
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }

    public Helper(int x) {
        this.x = x;
        this.result = 0;
        this.large = new TreeSet<>();
        this.small = new TreeSet<>();
        this.occ = new HashMap<>();
    }

    public void insert(int num) {
        if (occ.containsKey(num) && occ.get(num) > 0) {
            internalRemove(new Pair(occ.get(num), num));
        }
        occ.put(num, occ.getOrDefault(num, 0) + 1);
        internalInsert(new Pair(occ.get(num), num));
    }

    public void remove(int num) {
        internalRemove(new Pair(occ.get(num), num));
        occ.put(num, occ.get(num) - 1);
        if (occ.get(num) > 0) {
            internalInsert(new Pair(occ.get(num), num));
        }
    }

    public long get() {
        return result;
    }

    private void internalInsert(Pair p) {
        if (large.size() < x || p.compareTo(large.first()) > 0) {
            result += (long) p.first * p.second;
            large.add(p);
            if (large.size() > x) {
                Pair toRemove = large.first();
                result -= (long) toRemove.first * toRemove.second;
                large.remove(toRemove);
                small.add(toRemove);
            }
        } else {
            small.add(p);
        }
    }

    private void internalRemove(Pair p) {
        if (p.compareTo(large.first()) >= 0) {
            result -= (long) p.first * p.second;
            large.remove(p);
            if (!small.isEmpty()) {
                Pair toAdd = small.last();
                result += (long) toAdd.first * toAdd.second;
                small.remove(toAdd);
                large.add(toAdd);
            }
        } else {
            small.remove(p);
        }
    }
}

class Solution1 {
    public long[] findXSum(int[] nums, int k, int x) {
        Helper helper = new Helper(x);
        List<Long> ans = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            helper.insert(nums[i]);
            if (i >= k) {
                helper.remove(nums[i - k]);
            }
            if (i >= k - 1) {
                ans.add(helper.get());
            }
        }

        return ans.stream().mapToLong(Long::longValue).toArray();
    }
}
