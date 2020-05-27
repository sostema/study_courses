package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(doubleExpression(0.1, 0.2, 0.3));
    }
    public static boolean doubleExpression(double a, double b, double c) {
        return (a + b) > c - 0.0001 && (a + b) < c + 0.0001;
    }
}
