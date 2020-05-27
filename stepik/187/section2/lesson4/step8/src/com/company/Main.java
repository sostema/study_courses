package com.company;

import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        System.out.println(factorial(20).toString());
    }
    /**
     * Calculates factorial of given <code>value</code>.
     *
     * @param value positive number
     * @return factorial of <code>value</code>
     */
    public static BigInteger factorial(int value) {
        BigInteger fact = BigInteger.ONE;
        for (int i = 2; i <= value; ++i){
            fact = fact.multiply(new BigInteger(String.valueOf(i)));
        }
        return fact;
    }
}
