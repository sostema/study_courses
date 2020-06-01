package com.company;

import java.io.*;
import java.nio.charset.Charset;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    private static String readAsString(InputStream inputStream, Charset charset) throws IOException {
        // your implementation here
        int resultsRead, deltaStepOfArray = 512, beginIndex = 0, endIndex = deltaStepOfArray;
        byte[] bytes = new byte[endIndex], bytes1;
        do {
            resultsRead = inputStream.read();
            if (resultsRead > -1) {
                bytes[beginIndex] = (byte) resultsRead;
                beginIndex++;
                if (beginIndex == endIndex) {
                    endIndex += deltaStepOfArray;
                    bytes1 = Arrays.copyOf(bytes,endIndex);
                    bytes = bytes1;
                }
            }
        } while (resultsRead > -1);

        bytes1 = Arrays.copyOf(bytes, beginIndex);

        return new String(bytes1, charset);
    }
}
