package com.company;

import java.util.function.DoubleUnaryOperator;
public class Main {

    public static void main(String[] args) {
        System.out.println(integrate(x -> 1, 0, 10));
    }

    public static double integrate(DoubleUnaryOperator f, double a, double b) {
        double n = 0x1.0p25;
        double h = (b - a) / n;
        double result = 0;
        for (double i = 0; i < n; i++){
            result += f.applyAsDouble(a+i*h);
        }
        return h*result;
    }
}
