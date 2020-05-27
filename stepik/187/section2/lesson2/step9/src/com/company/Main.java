package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(isPowerOfTwo(1));
    }
    /**
     * Checks if given <code>value</code> is a power of two.
     *
     * @param value any number
     * @return <code>true</code> when <code>value</code> is power of two, <code>false</code> otherwise
     */
    public static boolean isPowerOfTwo(int value) {
        value = Math.abs(value);
        value = (Integer.numberOfTrailingZeros(value) + Integer.numberOfLeadingZeros(value));
        return value == 31;
    }
}
