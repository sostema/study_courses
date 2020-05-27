package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(flipBit(0, 1));
    }
    /**
     * Flips one bit of the given <code>value</code>.
     *
     * @param value     any number
     * @param bitIndex  index of the bit to flip, 1 <= bitIndex <= 32
     * @return new value with one bit flipped
     */
    public static int flipBit(int value, int bitIndex) {
        return value ^ 1 << --bitIndex;
    }
}
