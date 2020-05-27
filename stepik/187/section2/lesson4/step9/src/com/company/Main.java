package com.company;

public class Main {

    public static void main(String[] args) {

    }
    /**
     * Merges two given sorted arrays into one
     *
     * @param a1 first sorted array
     * @param a2 second sorted array
     * @return new array containing all elements from a1 and a2, sorted
     */
    public static int[] mergeArrays(int[] a1, int[] a2) {
        int i = 0, j = 0;
        int[] a3 = new int[a1.length + a2.length];

        while (i < a1.length && j < a2.length)
            a3[i + j] = (a1[i] < a2[j]) ? a1[i++] : a2[j++];
        while (i < a1.length)
            a3[i + j] = a1[i++];
        while (j < a2.length)
            a3[i + j] = a2[j++];
        return a3;
    }
}
