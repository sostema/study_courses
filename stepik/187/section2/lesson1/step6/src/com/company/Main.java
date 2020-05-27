package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(booleanExpression(false,false,true,true));
    }
    public static boolean booleanExpression(boolean a, boolean b, boolean c, boolean d) {
        return (a | b | c | d) && !(a & b & c & d) && !(a ^ b ^ c ^ d);
    }
}
