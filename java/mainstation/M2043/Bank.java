package com.cqupt.leetcode.mainstation.M2043;

import java.util.Arrays;

public class Bank {

    private final long[] balance;

    public Bank(long[] balance) {
        this.balance = balance;
    }

    private boolean check(int account) {
        return account >= 1 && account <= balance.length;
    }

    public boolean transfer(int account1, int account2, long money) {
        if (!check(account1) || !check(account2)) {
//                System.out.println(account1);
//                System.out.println(account2);
            return false;
        }
        System.out.println(Arrays.toString(this.balance));
        if (balance[account1 - 1] >= money) {
            this.balance[account1 - 1] -= money;
            this.balance[account2 - 1] += money;
            return true;
        }
        return false;
    }

    public boolean deposit(int account, long money) {
        if (!check(account)) {
            return false;
        }
        this.balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if (!check(account)) {
            return false;
        }
        if (this.balance[account - 1] >= money) {
            this.balance[account - 1] -= money;
            return true;
        }
        return false;
    }
}
