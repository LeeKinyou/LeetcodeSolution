class Solution {
public:
    int work(vector<int>& nums, int l, int r, int depth) {
        // System.out.println(l + " " + r + " " + depth);
        int minNum = 0x7f7f7f7f, cnt;
        for (int i = l; i < r; i++) {
            minNum = minNum < nums[i] ? minNum : nums[i];
        }
        if (minNum == 0) {
            cnt = 0;
        } else {
            cnt = 1;
        }
        int lef = l, rig = -1;
        if (l == r - 1 && minNum != 0) {
            return 1;
        }
        if (l == r - 1 && minNum == 0) {
            return 0;
        }
        for (int i = l; i < r; i++) {
            if (nums[i] == minNum) {
                rig = i;
                if (lef != rig) {
                    cnt += work(nums, lef, rig, depth + 1);
                }
                lef = i + 1;
            }
            if (i == r - 1 && lef != r) {
                cnt += work(nums, lef, r, depth + 1);
            }
        }
        return cnt;
    }

    int minOperations(vector<int>& nums) {
        return work(nums, 0, nums.size(), 0);
    }
};