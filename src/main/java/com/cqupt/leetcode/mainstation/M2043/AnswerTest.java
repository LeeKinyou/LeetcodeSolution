package com.cqupt.leetcode.mainstation.M2043;

import org.junit.Test;

public class AnswerTest {
    @Test
    public void test() {
        Bank bank = new Bank(new long[]{10, 100, 20, 50, 30});
        System.out.println(bank.withdraw(3, 10));
        System.out.println(bank.transfer(5, 1, 20));
        System.out.println(bank.deposit(5, 20));
        System.out.println(bank.transfer(3, 4, 15));
        System.out.println(bank.withdraw(10, 50));
    }
}
