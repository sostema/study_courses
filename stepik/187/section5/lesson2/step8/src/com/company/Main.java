package com.company;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStream stream;
        int result;
        stream = getStream( new byte[] { 0x33, 0x45, 0x01});

        result = checkSumOfStream(stream);
        System.out.print(result);
    }

    public static InputStream getStream(byte [] data)  {
        return new ByteArrayInputStream(data);
    }

    public static int checkSumOfStream(InputStream inputStream) throws IOException {
        int C = 0;
        for(int i = inputStream.read(); i != -1; i = inputStream.read()) {
            C = (int) (Integer.rotateLeft(C, 1) ^ (int) (i&0xFF));
        }
        return C;
    }
}
