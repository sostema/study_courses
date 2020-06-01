package com.company;

import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        int lastI = -1;
        for (int i = System.in.read(); i != -1; i = System.in.read()){
            if (lastI==13 & i==10){
                lastI = i;
                continue;
            }
            if (lastI != -1){
                System.out.write(lastI);
            }
            lastI = i;
        }
        if (lastI != -1){
            System.out.write(lastI);
        }
        System.out.flush();
    }
}
