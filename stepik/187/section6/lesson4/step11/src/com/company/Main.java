package com.company;

import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    private static IntStream pseudoRandomStream(int seed) {

        return IntStream.iterate(seed, n -> {
            String mr = String.valueOf(n * n);
            int endIndex    = (mr.length() < 1) ? 0 : mr.length() - 1,
                    beginIndex  = (mr.length() < 4) ? 0 : endIndex - 3;
            return (endIndex - beginIndex == 0) ? 0 : Integer.parseInt(mr.substring(beginIndex, endIndex),10);
        });

    }
}
